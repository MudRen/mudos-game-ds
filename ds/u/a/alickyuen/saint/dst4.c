#include <ansi.h>
//update 26/12
inherit ROOM;
void create()
{
	set("short", HIC"ST。Road＠South"NOR);
	set("long", @LONG
由於南面就是城門，所以這裡終日非常多人，更是離開Saint的主要通
道。而北面就可以進入繁華的Saint City Centre。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gate1.c",
  "north" : __DIR__"dst1.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
