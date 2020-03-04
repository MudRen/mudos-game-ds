// Room: /open/world1/dragoncity/westgate1.c

inherit ROOM;

void create()
{
	set("short", "白虎內門");
	set("long", @LONG
這裡是磐龍城的西城門的內城門，只見城門上方是三個大字。

[1;36m                      白虎門
[0m
LONG
	);
	set("outdoors", "land");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 4,
]));
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"west_din",
  "west" : __DIR__"westgate2",
  "westup" : __DIR__"wallw1",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
