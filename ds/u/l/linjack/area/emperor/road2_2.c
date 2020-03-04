#include <room.h>
inherit ROOM;
void create()
{
 set("short","彎道");
 set("long",@LONG
這邊是皇城轄區的最外圍了, 經過了這個彎道, 就會接到
往南方去的叉路口, 聽說南邊不遠處有一個大房子中不知道住
了何方神聖, 你可以過去一探究竟.
LONG
    );
 set("exits",([ "northeast":__DIR__"road2_1",
                "north":__DIR__"market2",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}