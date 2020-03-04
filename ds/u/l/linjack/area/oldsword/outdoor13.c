#include <room.h>
inherit ROOM;
void create()
{
 set("short","神秘的山壁");
 set("long",@LONG
你來到一個山壁之下, 山壁上畫了一個奇怪的圖案, 
像是一個有排列的陣形, 不過你也看不出它的順序是什
麼.
LONG
    );
 set("exits",([ "south":__DIR__"outdoor12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}