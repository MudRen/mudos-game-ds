#include <room.h>
inherit ROOM;
void create()
{
 set("short","山壁下");
 set("long",@LONG
這邊的泉水已經集結成一個小水窪, 不知怎麼著, 水窪
中竟隱隱透出奇異的光芒, 到底有什麼神奇之處呢?
LONG
    );
 set("exits",([ "east":__DIR__"outroom24",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
