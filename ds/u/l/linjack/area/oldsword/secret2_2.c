#include <room.h>
inherit ROOM;
void create()
{
 set("short","叉路口");
 set("long",@LONG
這邊有三條分岐的路線, 從東北方迎面吹來一股冷風, 而往東走
似乎還有一條很長的路. 往西南走則比較幽暗, 看不清楚狀況.
LONG
    );
 set("exits",([ "northeast":__DIR__"secret2_3",
                "southwest":__DIR__"secret2_1",
                "east":__DIR__":secret2_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
