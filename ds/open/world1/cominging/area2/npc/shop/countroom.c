#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Temp Room");
	set("long", @LONG

IT just a temp room.. don't come here.

LONG
	);
	set("objects",([
  COMINGING_PAST+"area2/npc/counter.c":1,
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}