#include <room.h>
inherit ROOM;
void create()
{
 set("short","死路");
 set("long",@LONG
你竟來到一個死路之中, 回去就是走到八陣圖之中了, 可是你
看到地上有一個箱子. 是否開該打開它呢?
LONG
    );
 set("exits",([ "south":__DIR__"secret6_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
