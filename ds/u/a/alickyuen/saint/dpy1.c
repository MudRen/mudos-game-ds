#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST.FIRE＠DPY"NOR);
	set("long", @LONG
這裡就是年輕人的假日熱點--DPY了。在這裡你可以盡情狂歡了，也可
以在這裡結識到很多朋友。但看到這門口的裝潢非常美麗，就知道可以好
好玩一晚了。
LONG
	);
 set("exits",([ 
"out":__DIR__"dst1.c",
"down":__DIR__"dpy2.c",
]));
        set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/bar" : 1,
]));
	set("light", 1);
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
