#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"針林"NOR);
 set("long",@LONG
這裡再往西走就出了寒穴了, 也就是說氣溫即將回到常溫, 
但是你還是可以在這裡找到你所要的藥材.
LONG
    );
 set("exits",([ "west":__DIR__"med17",
		"east":__DIR__"med13",
		"south":__DIR__"med15",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}