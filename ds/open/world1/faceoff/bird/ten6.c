#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","寨門");

 set("long",@LONG
你壯著膽子進了寨門, 只見四周的守衛相當嚴密, 壁上還有
一些箭孔可以向外射箭, 不要說官兵根本不管這裡, 就算要管, 
要進攻進去也很難.
LONG
    );
 set("exits",([ "east":__DIR__"ten7", 
		"out":__DIR__"ten5",
		"north":__DIR__"ten16",
    ]));
 set("objects", ([__DIR__"npc/bandit" : 2,
    ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}

