// Room: /u/s/sonicct/area/road15.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
這是一條十分普通的街道•往北可以通往花園。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shop6",
  "south" : __DIR__"road11",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
