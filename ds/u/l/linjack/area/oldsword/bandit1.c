#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���p�|");
 set("long",@LONG
�A�@���i�o��, �Nı�o�����j��, �ϧA�����u����v�T,
�S����k�ݲM���A�쩳�b����, �γ\�A�i�H���^����˪L��
��. �o�䦳�@�ѵ±��������Aı�o�򰩮��M......
LONG
    );
 set("exits",([ "south":__DIR__"forest7",
                "east":__DIR__"bandit2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
