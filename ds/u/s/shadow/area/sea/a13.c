/**
 * Shadow's area [�򩳥@�� - �ʸT�� - a13]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIR"�ʸT��"NOR);
	set("long",@LONG
�@���\�]²�檺�p�ж��C
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

