#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坪上");
 set("long",@LONG
這邊已經是接近山壁的垂直方向了, 再往裡面走就到山
壁下面的凹槽了. 有許多小動物都在這邊出沒, 這邊正處於
山谷之中, 景色宜人.
LONG
    );
 set("exits",([ "south":__DIR__"outroom20",
                "north":__DIR__"outroom22",
                "west":__DIR__"outroom23",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
