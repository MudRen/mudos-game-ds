// Room: /u/m/matlab/area/r5.c

inherit ROOM;

void create()
{
	set("short", "前庭");
	set("long", @LONG
前方一片燈火通明，一掃之前的陰LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r4.c",
  "north" : __DIR__"r6.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
