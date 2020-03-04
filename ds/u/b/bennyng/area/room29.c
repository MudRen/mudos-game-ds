// Room: /u/b/bennyng/area/room29.c

inherit ROOM;

void create()
{
	set("short", "寶瓶宮入口");
	set("long", @LONG
這裡被一層雪白的凍氣所包圍，四處死寂一片，只有一些守衛守著，
你感到出路必有事情發生，但你仍摸不著頭腦，彷彿會走進一條不歸路．
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"room30",
  "west" : __DIR__"room28",
]));
        set("objects", ([
  __DIR__"npc/guard.c":2,
]));
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
