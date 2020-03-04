// Room: /open/world1/dragoncity/eastgate1.c

inherit ROOM;

void create()
{
	set("short", "青龍內門");
	set("long", @LONG
這裡是磐龍城的南城門的內城門，只見城門上方是三個大字。

[1;36m                      青龍門
[0m
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 4,
]));
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"eastgate2",
  "eastup" : __DIR__"walle1",
  "west" : __DIR__"east_din",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
