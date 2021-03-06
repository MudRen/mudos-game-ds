// Room: /u/t/tmr/room/t1.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
一座不大的庭院，往南就是「奇」的書房，
只是門口站著兩個護衛，看來想進去書房...
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"square.c",
  "south" : __DIR__"bookroom.c",
]));
       create_door("south", "木門", "north", DOOR_CLOSED);
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/guard" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
