// Room: /open/world1/tmr/dragoncity/westgate2.c

inherit ROOM;

void create()
{
	set("short", "白虎外門");
	set("long", @LONG
這裡是磐龍城的西城門的外城門，只見城門上方是三個大字。

[1;36m                      白虎門
[0m
LONG
	);
	set("current_light", 3);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"westgate1",
  "northwest" : "/open/world1/tmr/hasake/gebi1",
]));

	setup();
	replace_program(ROOM);
}
