// Room: /open/world1/tmr/hasake/senlin3.c

inherit ROOM;

void create()
{
	set("short", "針葉林");
	set("long", @LONG
這是極西天山腳下的一片針葉林，林中鳥獸成群，滿地鋪蓋著厚厚一
層鬆針。西北方的一座高聳的山脈便是天山了，山上終年積雪，山下卻是
綠樹成蔭。往東南走便是大草原，有辛勤的哈薩克族人在那裡放牧。你走
著走著，竟然迷失了道路。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"senlin4",
  "north" : __DIR__"senlin13",
  "south" : __DIR__"senlin14",
  "east" : __DIR__"senlin2",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wolf1" : 2,
  __DIR__"npc/wolf2" : 1,
]));

	setup();
	replace_program(ROOM);
}
