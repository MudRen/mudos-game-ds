// http.c
//
//	WWW Server
//
// Kenny@EC (1997/8/7)

#include <runtime_config.h>
#include <net/macros.h>
#include <net/socket.h>
#include <net/http.h>

#define MAX_RETRIES	3
#define HTTP_HEADER 	"HTTP/1.0 %s%c"
#define DEFAULT_HEADER 	"Server: "+Mud_name()+"/0.1\nMIME-version: 1.0%c"
#define log_info(x, y) 	log_file(x, "["+ctime(time())+"] "+y)

protected int httpSock;
protected mapping sockets=([ ]);
protected mapping hex=(['0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6,
  '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11, 'C': 12, 'D': 13,
  'E': 14, 'F': 15, ]);
protected int MAX_BYTE_TRANSFER=get_config(__MAX_BYTE_TRANSFER__);


protected void setup()
{
    if ((httpSock=socket_create(STREAM, "read_callback", "close_callback")) < 0)
    {
	log_info(HTTPD_LOG, "setup: Failed to create socket\n");
	return;
    }
    if (socket_bind(httpSock, HTTPD_PORT) < 0)
    {
	socket_close(httpSock);
	log_info(HTTPD_LOG, "setup: Failed to bind socket to port\n");
	return;
    }
    if (socket_listen(httpSock, "listen_callback") < 0)
    {
	socket_close(httpSock);
	log_info(HTTPD_LOG, "setup: Failed to listen to socket\n");
    }
}


void create()
{
    log_info(HTTPD_LOG, "Created\n");
    call_out("setup", 5);
    set_reset(this_object(), 86400);
}


void remove()
{
    log_info(HTTPD_LOG, "Destructed\n\n");
}


protected string http_header(string code)
{
    return sprintf(HTTP_HEADER, code, 10) + sprintf(DEFAULT_HEADER, 10);
}


protected string http_error_header(string code)
{
    return http_header(code) + sprintf("Content-type: text/html%c%c", 10, 10);
}


protected void store_client_info(int fd)
{
    string 	addr;
    int	port;

    sscanf(socket_address(fd), "%s %d", addr, port);
    sockets[fd] = ([
      "address": addr,
      "port":    port,
      "status":  EESUCCESS,
    ]);
}


protected void close_connection(int fd)
{
    if (undefinedp(sockets[fd]) || !mapp(sockets[fd]) ||
      sockets[fd]["status"]==EECALLBACK)
	return;
    map_delete(sockets, fd);
    socket_close(fd);
}


protected void write_data_retry(int fd, mixed data, int count, int no_close)
{
    int rc;

    if (count>=MAX_RETRIES || !mapp(sockets[fd]))
	return close_connection(fd);
    rc = socket_write(fd, data);
    sockets[fd]["status"] = rc;
    switch (rc)
    {
    case EESUCCESS:
	if (!no_close) close_connection(fd);
	break;
    case EEALREADY:
	sockets[fd]["pending"] = data;
	break;
    case EECALLBACK:
	break;
    case EEWOULDBLOCK:
    case EESEND:
	if (count < MAX_RETRIES)
	{
	    call_out("retry_write", 2, ({ fd, data, count+1, no_close }));
	    return;
	}
    default:
	log_info(HTTPD_LOG, "write_data_retry: "+socket_error(rc)+"\n");
	close_connection(fd);
    }
}


protected void retry_write(mixed *args)
{
    write_data_retry(args[0], args[1], args[2], args[3]);
}


protected varargs void write_data(int fd, mixed data, int no_close)
{
    write_data_retry(fd, data, 0, no_close);
}


protected void write_callback(int fd)
{
    if (sockets[fd]["status"] == EEALREADY)
    {
	write_data(fd, sockets[fd]["pending"]);
	map_delete(sockets[fd], "pending");
    }
    else
    {
	sockets[fd]["status"] = EESUCCESS;
	close_connection(fd);
    }
}


string parse_path(string path)
{
    string uid;

    if (!stringp(path))	return 0;

    if (strlen(path)>2 && path[1]=='~') // personal directory
    {
	if (sscanf(path, "/~%s/%*s", uid) != 1)
	    sscanf(path, "/~%s", uid);
	if (stringp(uid) && uid!="")
	{
	    if (uid[<1] == '/') uid = uid[0..<2];
	    path = replace_string(path, "/~"+uid, user_cwd(uid)+USER_DIR);
	}
    }
    else	path = SERVER_ROOT + path;

    if (file_size(path) == -2) // directory
	if (path[<1] != '/') path += "/";
    if (path[<1] == '/')	path += WELCOME;
    return path;
} // parse_path()


protected void http_error(int fd, mapping err, string code)
{
    write_data(fd, http_error_header(code)+read_file(parse_path(err["file"]))+sprintf("%c%c", 10, 10));
}


protected void log_http(int fd, int rc, int nbytes, string cmd)
{
    if (!sockets[fd]) return;
    log_info(HTTPD_LOG, sprintf("%s %s %d %s\n",
	sockets[fd]["address"], cmd, rc,
	nbytes? (nbytes+""): "-"));
}


protected mapping parse_cgi_arg(string arg_str)
{
    string  *arg_list, var, val;
    mapping args=([ ]);

    if (stringp(arg_str) && arg_str!="")
    {
	arg_list = explode(arg_str, "&");
	foreach (string pair in arg_list)
	{
	    int i, j;

	    sscanf(pair, "%s=%s", var, val);
	    val = replace_string(val, "+", " ");
	    for (i=0; i<strlen(val) && (j=strsrch(val[i..<1], '%'))>=0; i++)
	    {
		i += j;
		if (strlen(val[i..<1])>2 &&
		  !undefinedp(hex[val[i+1]]) &&
		  !undefinedp(hex[val[i+2]]) )
		    val = replace_string(val,
		      val[i..i+2],
		      sprintf("%c", hex[val[i+1]]*16+hex[val[i+2]]) );
	    }
	    args += ([ var: val ]);
	}
    } // if arg_str

    return args;
} // parse_cgi_arg()


protected string exec_cgi(string path, mapping arg_list, int fd)
{
    object cgi;
    string page;

    if (!stringp(path) || path=="") return 0;
    if (!mapp(arg_list)) arg_list = ([ ]);

    if (file_size(path) < 0)
    {
	log_http(fd, 404, 0, path);
	http_error(fd, NOT_FOUND, "404 Not Found");
    }
    if (!find_object(path) && catch(path->foo()) )
    {
	log_http(fd, 400, 0, path);
	http_error(fd, BAD_CGI, "400 Bad Request");
    }
    else
    {
	cgi = find_object(path);
	if (!stringp(page=cgi->main(arg_list)))
	{
	    log_http(fd, 400, 0, path);
	    http_error(fd, BAD_CGI, "400 Bad Request");
	}
    } // else found path

    return page;
} // exec_cgi()


protected string process_cgi(string page, mapping arg, int fd)
{
    int     idx;
    string  src, path, arg_str, dst;
    mapping arg_list;

    if (!stringp(page) || page=="") return 0;
    if (!mapp(arg)) arg = ([ ]);

    while ((idx=strsrch(page, "<!-- "+CGI_TAG+"=\"")) >= 0)
    {
	sscanf(page[idx..<1], "<!-- "+CGI_TAG+"=\"%s\" -->%*s", src);
	if (stringp(src) && src!="")
	    if (sscanf(src, "%s?%s", path, arg_str) != 2)
		path = src;
	path = parse_path(path);
	arg_list = parse_cgi_arg(arg_str);
	if (!stringp(dst = exec_cgi(path, arg_list+arg, fd) )) dst = "";
	page = replace_string(page, "<!-- "+CGI_TAG+"=\""+src+"\" -->", dst);
    } // while found CGI_TAG

    return page;
} // process_cgi()


protected void do_get(int fd, string path, string line0)
{
    string  arg_str, page;
    mapping arg_list=([ ]);
    buffer  data;

    path = parse_path(path);
    sscanf(path, "%s?%s", path, arg_str);
    if (stringp(path) && sizeof(path)>2 && path[<2..<1]==".c")
    {
	arg_list += parse_cgi_arg(arg_str);
	if (stringp(page=exec_cgi(path, arg_list, fd)) )
	    if (stringp(page=process_cgi(page, arg_list, fd)))
		write_data(fd, page);
    } // if cgi
    else if (sizeof(path)>5 && path[<5..<1]==".html")
    {
	page = read_file(path);
	if (stringp(page))
	{
	    if (stringp(page=process_cgi(page, arg_list, fd)))
		write_data(fd, page, 1);
	    log_http(fd, 200, sizeof(page), path);
	    close_connection(fd);
	}
	else if (file_size(path) != -1)
	{
	    log_http(fd, 403, 0, path);
	    http_error(fd, ACCESS_DENIED, "403 Forbidden");
	}
	else
	{
	    log_http(fd, 404, 0, path);
	    http_error(fd, NOT_FOUND, "404 Not Found");
	}
    } // elseif html
    else
    {
	int filesize;

	if ((filesize=file_size(path)) == -2)
	{
	    log_http(fd, 403, 0, path);
	    http_error(fd, ACCESS_DENIED, "403 Forbidden");
	}
	else if (filesize == -1)
	{
	    log_http(fd, 404, 0, path);
	    http_error(fd, NOT_FOUND, "404 Not Found");
	}
	for (int length=0; length<filesize; length+=__MAX_BYTE_TRANSFER__)
	{
	    reset_eval_cost();
	    if (bufferp(data=read_buffer(path, length, __MAX_BYTE_TRANSFER__)))
		write_data(fd, data, 1);
	}
	log_http(fd, 200, filesize, path);
	close_connection(fd);
    } // else bin file
}


protected void do_post(int fd, string file, string url, string line0)
{
    do_get(fd, file+"?"+url, line0);
}


protected void read_callback(int fd, string str)
{
    string tmp, *request, cmd, file, args;

    if (!str || str=="") return http_error(fd, BAD_CMD, "400 Bad Request");
    if (tmp = sockets[fd]["read"]) str = tmp + str;
    if (str[<1] != '\n')
    {
	sockets[fd]["read"] = str;
	return;
    }
    else	map_delete(sockets[fd], "read");

    request = explode(replace_string(str, "\r", ""), "\n");
    if (!arrayp(request) || sizeof(request)<1) return;
    if (sscanf(request[0], "%s %s %s", cmd, file, args) != 3) return;
    switch(lower_case(cmd))
    {
    case "get":
	do_get(fd, file, request[0]);
	break;
    case "post":
	do_post(fd, file, request[<1], request[0]);
	break;
    default:
	http_error(fd, BAD_CMD, "400 Bad Request");
    }	
}


protected void close_callback(int fd)
{
    if (fd == httpSock)
    {
	log_info(HTTPD_LOG, "HTTP socket closed unexpectedly; restarting\n");
	call_out("setup", 5);
    }
    else
    {
	if (undefinedp(sockets[fd]))
	    log_info(HTTPD_LOG, sprintf("Client socket %d closed unexpectedly\n", fd));
	else
	    log_info(HTTPD_LOG, sprintf("Client socket %s %d closed unexpectedly\n",
		sockets[fd]["address"], sockets[fd]["port"]));
	map_delete(sockets, fd);
    }
}


protected void listen_callback(int fd)
{
    int nfd;

    if ((nfd=socket_accept(fd, "read_callback", "write_callback")) < 0)
    {
	log_info(HTTPD_LOG, "listen_callback: socket_accept failed\n");
	return;
    }
    store_client_info(nfd);
}
