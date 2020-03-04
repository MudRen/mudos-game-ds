#include <room.h>
inherit ROOM;
void create()
{
 set("short","道路上");
 set("long",@LONG
通過了這段小路, 你終於走到大路上來了, 果然和
步靈城那兒不太一樣. 但是你總是看不到像步靈城那樣
洶湧的人潮在這邊出現.
LONG
    );
 set("exits",([ "northeast":__DIR__"path2",
                "southwest":__DIR__"road2",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}
