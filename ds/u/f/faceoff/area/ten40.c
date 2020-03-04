#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","青石路");

 set("long",@LONG
到青石路的盡頭了, 你發現原來天梟分裂後, 梟像一直在
天梟冶藥一派被供俸著, 一方面也是因為天梟冶藥一派的殺氣較
低, 一方面大概也是因為較近吧....從這裡往東就會進入天梟之
中.
LONG
    );
 set("exits",([	"east":__DIR__"ten41",
		"south":__DIR__"ten39",
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}