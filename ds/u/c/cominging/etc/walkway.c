#include <ansi.h>
#include <net/socket.h>
#include <socket_err.h>

inherit ITEM;

static int m_socket;
static int socket_no1;
static int socket_no2;
static object me;
static int status=0;

object telnet = this_object();

int write_message(string); 

void listen(string arg){tell_object(environment(telnet),arg);}

void create()   
{
        set_name("����", ({ "cloth" }) );
        set_max_encumbrance(0); 
        set("value",999);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "�j��");
        }
        setup();
}

void init()
{
        set_temp("invis", 100);
        set_temp("ridon", 1);
        add_action("close_socket","close");
        add_action("write_message","//");
        add_action("do_telnet","telnet");
        add_action("do_codo", "codo");
}

int do_telnet(string arg)
{
        int err;
        if( query("connected") )
                socket_close(m_socket);
        
        m_socket = socket_create(STREAM, "in_read_callback","in_close_callback" );
        
        if ( m_socket < 0 )
        {
                listen("�L�k��l�� Socket .\n" );
                return 1;
        }
        
        err = socket_connect(m_socket,arg,"read_callback","write_callback" );
        
        if( err==EESUCCESS )
        {
                listen("���s�u�� - " + arg + "\n");
                set("connected",1);
        }
        else listen("�L�k�s�u�� - " + arg + " ���~ : "+ err +"\n");

        return 1;
}

int close_socket()
{
        if( query("connected") )
        {
                if( socket_close(m_socket) )
                {
                        listen("���� telnet socket!!\n");
                        delete("connected");
                }
                else listen("���� telnet socket �X��.\n");
        }
        else listen("�ثe�èS���s�u�C\n");

        return 1;
}

void read_callback(int fd, mixed message)
{
	if( stringp(message) )
	{
		if( strsrch(message, "�i�F��j") != -1 )
			write_file(__DIR__"es_log", message);

		if( strsrch(message, "�i�Ův�j") != -1 || strsrch(message, "�i�x�W�j") != -1 )
			write_file(__DIR__"wiz_only_log", message);

		if( strsrch(message, "�i����j") != -1 || strsrch(message, "�i�ʧ@�j") != -1 )
			write_file(__DIR__"tchat_log", message);

		if( strsrch(message, "�i�g�s���j") >= 0 || strsrch(message, "�i��ڡj") >= 0 || strsrch(message, "�i�Ѧa�|�j") >= 0 )
			write_file(__DIR__"club_log", message);

		if( strsrch(message, "�i�j�N�j") >= 0
		|| strsrch(message, "�i�{�N�j") >= 0
		|| strsrch(message, "�i���ӡj") >= 0 )
			write_file(__DIR__"talk_log", message);
	}
        listen(HIY"��"NOR + (message));return;
}

void write_callback(int fd)
{
        int sta;
        
        if( query("connect") ) return ;
        
        sta = socket_write( fd,"");
        
        if (sta == EESUCCESS || sta == EECALLBACK)
                set("connected",1);
        
}

int write_message(string arg)
{
        if( !arg ) arg = "";
        
        socket_write(m_socket,arg+"\n"); // \n = enter keys _
        
        return 1;
}

int codo(string arg)
{
	string *str;
	if( !arg )
	{
		write("�۰ʨϥΥH 'idle;sleep;who-l' �������u.\n");
		arg = "who -l;sleep;idle";
	}
	if( strsrch(arg, "quit") >= 0 )
		return notify_fail("����� quit !\n");
	if( sizeof(str=explode(arg, ";")) < 1 )
		return notify_fail("�ǤJ�۰� cmd �Ӥ֡I\n");

	remove_call_out("codo_2nd");

	call_out("codo_2nd", 300, str);
	return 1;
}

void codo_2nd(string *str)
{
	int x = random(sizeof(str));

	if( str[x] == "" )
	{
		call_out("codo_2nd", 300, str);
		return;
	}

	socket_write(m_socket, str[x] + "\n");

	call_out("codo_2nd", 300, str);
}