// Room: /open/world1/tmr/area/street5.c

inherit ROOM;

void create()
{
	set("short", "大街");
	set("long", @LONG
你正走在一條廣大熱鬧的街道，街上行人川流不息，大多是趕往南邊
的市集所在，附近有名的朝天樓就座落於北邊的大街旁，在西邊有條小巷
子，在繁雜的過往人群中望去，倒不易發現到。
LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("outdoors", "land");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/aya" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"street4",
  "east" : "/open/world1/cominging/area/dragon/dragon_door.c",
  "west" : __DIR__"wynd",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
