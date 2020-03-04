/**
 * Shadow's area [湖底世界 - 監禁室 - a13]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIR"監禁室"NOR);
	set("long",@LONG
一個擺設簡單的小房間。
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"west" : __DIR__"a12",
	]));

	setup();
	replace_program(ROOM);
}

