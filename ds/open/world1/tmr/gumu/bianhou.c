// Room: /d/gumu/bianhou.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIB"匾后"NOR);
	set("long", @LONG
這里就是古墓中堂匾額之后，黑漆漆的什么都看不清楚。匾下石室
里點著燭火，一片暈黃。里面似乎還有一條通道。
LONG	);
	set("exits",([
		"down"  : __DIR__"zhongting",
		"enter" : __DIR__"mishi1",
	]));
	set("objects",([
		__DIR__"obj/silverkey" : 1,
	]));
	setup();
	replace_program(ROOM);
}
