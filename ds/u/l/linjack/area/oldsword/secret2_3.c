#include <room.h>
inherit ROOM;
void create()
{
 set("short","叉路口");
 set("long",@LONG
這邊有三條分岐的路線, 東邊似乎就是出口了, 強風不斷滲入,
而往西走和南走則比較幽暗, 看不清楚狀況.
LONG
    );
 set("exits",([ "east":__DIR__"secret2_5",
                "southwest":__DIR__"secret2_2",
                "west":__DIR__":secret2_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
