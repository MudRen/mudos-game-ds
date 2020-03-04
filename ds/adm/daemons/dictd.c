/******�^���r�d�ߨt��*******************by whatup 01/07/15
  �ثe�O�Q�Φ������@�d�� http://www.ee.tku.edu.tw/~rexchen/
                                      ==���g�P�N, �Y�T�y�X==
************************************************************/
// Cominging �令 �IĶ�q
// http://www.dreye.com/tw/dict/dict.phtml?w=%s&d=010300&account=123456&ver=big5&show=0&repeat=1
// Dr. Eye
#include <ansi.h>
#include <net/socket.h>
#include <socket_err.h>

inherit F_DBASE;

string strs = "";
string *html = ({
"</div>",
"<div class=pcixin>",
"<div class=pexplain>",
"<div class=peng>",
"<span id=dropdownid>",
"<div class=pchi>",
"</span>",
"<font class=engi>",
"</font>"
});
string *html_m = ({
"\n"NOR,
HIR,
"  ",
"    ",
"",
"    ",
"",
"",
"",
});

// string simplex; /* �d�ߪ���r */
// object tu;/* ��T���ǵ�user�ݨ� */
mapping connects=([]);
protected void get_data(int);

void create()
{
    seteuid(getuid());
    set("name","�^���r���F");
    set("id","dict");
}

void find_word(object user,string word)
{
        int err, fd;
        if(!user) return ;
        if(!word) return ;              
                
        /* �}�Һ����s�� */
        fd = socket_create(STREAM, "read_callback","close_socket");
        if ( fd < 0 ){
                tell_object(user,HIR"a�d�ߥ���, �еy��b�աC\n"NOR);                     
                return;
        }
        err = socket_connect(fd, "211.20.181.29 80","read_callback","write_callback" );
        if( err != EESUCCESS ){
                CHANNEL_D->do_channel(this_object(),"sys", "["+time()+"]�Ұ� Socket ����,�L�k������.\n");
                tell_object(user,HIR"b�d�ߥ���, �еy��b�աC\n"NOR);     
                return ;
        }          
        connects[fd] = allocate_mapping(3);
        connects[fd]["data"] = "";
        connects[fd]["user"] = user;
        connects[fd]["simplex"] = word;

        return ;
}

int close_socket(int fd)
{
        socket_close(fd);
        get_data(fd);
}

void read_callback(int fd, mixed message)
{
        connects[fd]["data"] += message;
        return ;
}

void write_callback(int fd)
{
        socket_write(fd, sprintf("GET /tw/dict/dict.phtml?w=%s&d=010300&account=123456&ver=big5&show=0&repeat=1\r\n", connects[fd]["simplex"]));
        return ;
}

protected void get_data(int fd)
{
        string str;
        str = "";
        if( sscanf(connects[fd]["data"], "%*s<div class=pcixin>%s<center>%*s", str) != 3) {
                tell_object(connects[fd]["user"], HIR"�õL���r�C\n"NOR);
                return ;
        }
        else str = HIR+str;

        for(int x=0;x<sizeof(html);x++)
                str = replace_string(str, html[x], html_m[x]);
        str = replace_string(str, connects[fd]["simplex"], HIY+connects[fd]["simplex"]+NOR);
        str = sprintf(HIC"�z�d�ߪ���r�� : %s "NOR"\n%s\n", connects[fd]["simplex"], str);
        tell_object(connects[fd]["user"], str);
        return ;
}       

