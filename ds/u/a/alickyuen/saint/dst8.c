//updated 26/12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST。Road＠North"NOR);
	set("long", "這裡是Saint內的其中一條街道，這裡給你的感覺十分好，因為這裡
比較安靜吧！但有時卻因為機械人在巡邏的關係而變得有些嘈吵，另人感
到有些煩惱。\n");
 set("exits",([ 
"north":__DIR__"dst9.c",
"south":__DIR__"dst5.c",
]));
set("outdoors","land");
	setup();
	replace_program(ROOM);
}
