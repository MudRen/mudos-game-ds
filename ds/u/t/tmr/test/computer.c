#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>
inherit ITEM;

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
set_name(HIW"連線遊戲機"NOR, ({ "computer" }) );

         set("long", @LONG
telnet 203.71.167.75 5000

連線中...............

               ▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂
                               - 風之物語 -
               �m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m

                   | -                                - |
                           本 Mud 是承襲 Es2lib
                   | -                                - |

                        * 本站設置於 1999 年 6 月 *
                          BBS :  203.72.48.43 tww_mud版
                          WizMud : 203.71.167.75 9000


                oOＯOo   想玩嗎？進來就知道多好玩   oOＯOo



風之物語已經在風中飄蕩了一天一小時五十二分二十八秒

目前共有 2 位巫師、6 位玩家在線上﹐以及 2 位使用者嘗試連線中。

您的英文名字﹕
LONG
        );

        set_max_encumbrance(0);
                if( clonep() )
                        set_default_object(__FILE__);
                else {  set("unit", "台");      }

                setup();
}
// Add_action For User
void init()
{
                add_action("close_socket","close");
                add_action("write_message","z");
                add_action("do_telnet","telnet");
}

// Telnet Login

int do_telnet(string arg)
{
        int err;
        if( query("connected") )
                        socket_close(m_socket);

        m_socket = socket_create(STREAM, "in_read_callback","in_close_callback");

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

