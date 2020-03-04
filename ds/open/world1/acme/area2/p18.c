// Room: /u/a/acme/area3/p18.c

inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
你正站在走道中，這是通往臥房的小道，此地燈光微暗，北邊施迅的
臥房，南邊則是客房，往東可至庭院。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"p19",
  "east" : __DIR__"p3",
  "south" : __DIR__"p20",
]));
        set("light",1);
set("objects",([
  __DIR__"npc/aw2" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
