/*
       �P�ڮ��l (���G��))

      make by Fan@falling-sun  date:10/12/98
      
      ��g��BIG5����. Luky@the.dream.of.seven  03/11/2000
*/

#include <net/socket.h>
#include <ansi.h>

inherit NPC;
inherit F_ALIAS;
inherit F_EDIT;
inherit F_MORE;
inherit F_MESSAGE;
inherit F_AUTOLOAD;
inherit F_SAVE;

static int telnet_socket;
static mapping con_to=([ ]);
static int in_putting = 0;
static string id;

void close_callback(int s);
string process_input(string str);
void read_callback(int s, mixed message);
void write_callback(int s,string message);
void close_callback(int s);
void select_connect(string arg);
void begin();

void create()
{
    set_name("���", ({ "space" }) );
    set("gender", "�k��" );
    set("long","�L�O�@�ӥѮɪ��ܧ����ܤƦӦ����H���C\n");
    set("title","�P�ڮ��l");
    set("race","human");
    set("age", 29);
    set("level",99);
    set("attitude", "heroism");
    set("no_kill",1);
    set("no_clean_up",1);
    setup();

}

string query_save_file()
{

        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s.s", id[0], id);
}

int new_possess(string arg)
{
    string uid;
    object me=this_player(),ob;
    uid=geteuid(me);
    if( this_object()->query_temp("possessed") || me->query_temp("possessed") ){
        write("����H\n");
        return 1;
    }
    me->save();
    message_vision("$N�Ʀ��@�D���~�A�Q$n�l�i�餺�C\n", me, this_object());
    set_name(me->query("name"),({ uid }) );
    if (SECURITY_D->get_wiz_level(me)>3){
	    seteuid(uid);
	    id=arg;
	    this_object()->restore();
    }
    exec(this_object(), me);
    ob=me->query_temp("link_ob");
    if(ob) this_object()->set_temp("login_ob",ob);
    destruct(me);
    this_object()->set_temp("possessed",1);
    this_object()->enable_player();
    call_out("begin",1);
    return 1;
}
void init()
{
   add_action("new_possess","possess");
}

void remove()
{
    close_callback(telnet_socket);
}

string process_input(string str)
{
    if (!in_putting) return ::process_input(str);
    if (sscanf(str,":%s",str)==1) return ::process_input(str);
    switch (str){
    case "E": str=ESC;  break;
    case "X": str="";   close_callback(telnet_socket);  break;
    }
    if( stringp(str) ) {
         if( interactive(this_object()) ) {
             if (con_to["language"]!="BIG5")
                 str = (string)LANGUAGE_D->Big52GB(str);
         }
     }
     write_callback(telnet_socket,str);
         return "";
}

void read_callback(int s, mixed message)
{
     if (con_to["language"]!="BIG5")
          message=(string)LANGUAGE_D->GB2Big5(message);
     write(NOR+BOLD+">>"+NOR+message);
}

void write_callback(int s,string message)
{
    int error;
    error = socket_write(telnet_socket, message+"\n");
    if (error < 0) {
        write("socket_write: " + socket_error(error) + "\n");
        close_callback(telnet_socket);
        call_out("begin",1);
        return;
    }
}

void close_callback(int s)
{
    write("��" + s + "���ɥ��G�D�w�g�����C\n");
    socket_close(s);
    in_putting=0;
    call_out("begin",1);
}
void begin()
{
    write(@NOTE

	�п�Jip port language:
	
	�Ҧp:
	
	[�ڤۤC��] 140.112.34.165 7000 BIG5
	[�j���p��] 140.119.75.11 5000 BIG5
	[����]     172.23.16.98 5555 GB
	[�������] 140.113.87.202 4000 BIG5
	      
	         == ��  x  �h�X == 

NOTE
);
    input_to("select_connect");
}
void select_connect(string arg)
{
    int error,temp_socket;
    string addr,port,language;
    object login_ob,user;
    if (!arg ){
       begin();
       return;
    }
    if (arg=="x"){
            command("quit");
	   return;
/*            if(login_ob=this_object()->query_temp("login_ob"))
            {
            	if(user = LOGIN_D->make_body(login_ob,login_ob->query("race")))
            	{
            		LOGIN_D->enter_world(login_ob, user, 1);
            		return;
            	}
            	else command("quit");
            }
            else command("quit");
            return;
*/
       }
    if (sscanf(arg,"%s %s %s",addr,port,language)!=3){
        if (sscanf(arg,"%s %s",addr,port)!=2){
            begin();
            return;
        }
        language="BIG5";
    }
    if (upper_case(language)!="GB")
        language="BIG5";

    con_to=([ "addr"    :   addr+" "+port,
              "language":   language,
    ]);
    temp_socket=socket_create(STREAM, "read_callback", "close_callback");
    telnet_socket=temp_socket;
    if (temp_socket < 0) {
       write("�i�J�ɥ��G�D�J��·�: " + socket_error(temp_socket) + "\n");
       begin();
       return;
    }
    write("�A���b�V��" + temp_socket + "���ɥ��G�D....\n\nX : �j�������ɥ��G�D
�A�G�R�O: �V�a�y�j����o�R�O�C\n");

    error = socket_connect(temp_socket, con_to["addr"], "read_callback", "writ
e_callback");
    if (error < 0 ) {
        write(HIR+"�@�ӵL�Ϊ��۴�: " + socket_error(error) + ",��A��F�^��...\n
"+NOR);
        close_callback(temp_socket);
        begin();
        return;
    }
    in_putting=1;
}
