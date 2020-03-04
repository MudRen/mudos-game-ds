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
        set_name("????????????", ({ "con" }) );
        set_max_encumbrance(0); 
        set("value",999);                if( clonep() )
                        set_default_object(__FILE__);
                else {  set("unit", "��");      }
        
                setup();
}

void init()
{     
                add_action("close_socket","close");
                add_action("write_message","//");
                add_action("do_telnet","telnet");
}

int do_telnet(string arg)
{
        int err;
        if( query("connected") )
                        socket_close(m_socket);
        
        m_socket = socket_create(STREAM, "in_read_callback","in_close_callback" );
        
        if ( m_socket < 0 ){
                listen("�L�k��l�� Socket .\n" );
                return 1;
        }
        
       err = socket_connect(m_socket,arg,"read_callback","write_callback" );
        
        if( err==EESUCCESS ) {
                listen("���s�u�� - " + arg + "\n");
                set("connected",1);
        }else
        
        listen("�L�k�s�u�� - " + arg + " ���~ : "+ err +"\n");
        return 1;
}

int close_socket()
{
        if( query("connected") ){
                        if( socket_close(m_socket) ) {
                                listen("���� telnet socket!!\n");
                                delete("connected");
                        }else
                                listen("���� telnet socket �X��.\n");
                }
        else    
                listen("�ثe�èS���s�u�C\n");
        return 1;
}

void read_callback(int fd, mixed message)
{
//        listen(HIY"��"NOR + LANGUAGE_D->toBig5((message)));return ;
        listen(YEL"��"NOR + message);return ;
}

void write_callback(int fd)
{
        int sta;
        
        if(query("connect"))
                return ;
        
        sta = socket_write( fd,"");
        
                if (sta == EESUCCESS || sta == EECALLBACK)
                        
                                set("connected",1);
        
}

int write_message(string arg)
{
        if( !arg ) arg=""; 
//        arg =LANGUAGE_D->Big52GB(arg);        
                socket_write(m_socket,arg+"\n"); // \n = enter keys _
        
        return 1;
}



