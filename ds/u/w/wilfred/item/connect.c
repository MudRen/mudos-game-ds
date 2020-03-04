inherit ITEM;
// Network Config Include 

#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>

// Static var
static int m_socket;
static int socket_no1;
static int socket_no2;
static object me;
static int status=0; // Create Socket status..

object telnet = this_object();

int write_message(string); // this Functoin Write Scoket Message. 

// Listen Socket Message For This User

void listen(string arg){tell_object(environment(telnet),arg);}

// Create This object .

void create()   
{
        set_name(HIC"�q�T��"NOR, ({ "telnet" }) );
        set_max_encumbrance(0);
                if( clonep() )
                        set_default_object(__FILE__);
                else {  set("unit", "��");      }
        
                setup();
}

// Add_action For User 

void init()
{     
                add_action("close_socket","close");
                add_action("write_message","//");
                add_action("do_telnet","telnet");
}

// Telnet Login 

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
        
        listen("�L�k�s�u�� - " + arg + "\n");
        return 1;
}

// Close This Socket

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

// socket listen Telnet Message_
 
void read_callback(int fd, mixed message)
{
        listen(HIY"��"NOR + (message));return ;
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
// Write Socket Message.

int write_message(string arg)
{
        if( !arg ) arg="";
        
                socket_write(m_socket,arg+"\n"); // \n = enter keys _
        
        return 1;
}


