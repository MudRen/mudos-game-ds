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
        set_name(HIC"通訊器"NOR, ({ "telnet" }) );
        set_max_encumbrance(0);
                if( clonep() )
                        set_default_object(__FILE__);
                else {  set("unit", "具");      }
        
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
                listen("無法初始化 Socket .\n" );
                return 1;
        }
        
       err = socket_connect(m_socket,arg,"read_callback","write_callback" );
        
        if( err==EESUCCESS ) {
                listen("正連線至 - " + arg + "\n");
                set("connected",1);
        }else
        
        listen("無法連線至 - " + arg + "\n");
        return 1;
}

// Close This Socket

int close_socket()
{
        if( query("connected") ){
                        if( socket_close(m_socket) ) {
                                listen("關閉 telnet socket!!\n");
                                delete("connected");
                        }else
                                listen("關閉 telnet socket 出錯.\n");
                }
        else    
                listen("目前並沒有連線。\n");
        return 1;
}

// socket listen Telnet Message_
 
void read_callback(int fd, mixed message)
{
        listen(HIY"→"NOR + (message));return ;
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


