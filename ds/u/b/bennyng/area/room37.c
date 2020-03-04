// Room: /u/b/bennyng/area/room37.c

inherit ROOM;

void create()
{
	set("short", "斷崖");
	set("long", @LONG
這條斷崖就是當年龍座紫龍與山羊座黃金聖鬥士修羅所交戰的地方，
就是因為修羅的一招聖劍，把這條通道變成斷崖，不可能走去對面，你只
有跳過去才有機會繼續前進．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room38",
  "north" : __DIR__"room36",
]));
        set("objects", ([
  __DIR__"npc/Capricorn.c":1,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
