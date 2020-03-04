#include <room.h>
inherit ROOM;
void create()
{
 set("short","叉路口");
 set("long",@LONG
這邊是皇城轄區的最外圍了, 經過了這個叉路口, 又會是
蒼松的古道和幽靜的天空, 聽說這兒的南邊不遠處有一棟大房
子, 不知道是誰在住的.
LONG
    );
 set("exits",([ "southwest":__DIR__"road2_2",
                "south":__DIR__"road2_3",
                "northwest":__DIR__"center",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}