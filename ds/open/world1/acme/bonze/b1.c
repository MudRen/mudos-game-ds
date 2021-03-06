// Room: /open/world1/acme/bonze/b1.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你走進一處人煙罕至的山道中，四方左右都是長高及腰的雜草，
遮蔽了視線，也阻擋了你行進的路線；環顧四週，你不自覺地有些膽
顫心驚，彷彿在隱藏的草叢中，有東西在窺伺你的一舉一動。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"b2",
"northwest" : TMR_PAST"area/lake-road3",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
