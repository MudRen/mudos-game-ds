// Room: /u/l/lestia/area/sn21.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG

你走進了一座古老的森林裡，四周的樹木濃密且筆直的排列著，四周是
一片霧濛濛的景象，你發現自己已經迷失了方向，四周安靜極了，前面的路
分成了好幾條，真不知道要走哪一條？

LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sn5",
  "north" : __DIR__"map_12_7",
  "west" : __DIR__"sn5",
  "south" : __DIR__"sn5",
]));
	set("world", "undefine");
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
