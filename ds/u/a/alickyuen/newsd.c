#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>

static int my_socket;
static object me;

int get_html();

void create()
{
        write( "���������Ƥ�, �еy�� ... \n");
        get_html();
}

int get_html()
{
        int err;

        my_socket = socket_create( STREAM, "read_callback","close_callback" );
        if ( my_socket < 0 )    return 1;

        err = socket_connect( my_socket,  "211.72.254.218 80" , "read_callback","write_callback" );

        if( err==EESUCCESS ) 
        {
                return 1;
        }
        else

                write("�s������ ....\n");

        return 1;
}

// �����s�� 
int close_socket()
{
        socket_close(my_socket);
        return 1;
}

// �^�Ǹ��
void read_callback(int fd, mixed msg)
{
        //tell_object( find_player("msr"), sprintf( "%O\n", msg ));

        rm( __DIR__"msg");

        write_file( __DIR__"msg", msg, 1);
        socket_close(my_socket);
}

void write_callback(int fd)
{
        socket_write( my_socket, sprintf("GET /index.html\r\n"));
}
