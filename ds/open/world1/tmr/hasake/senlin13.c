// Room: /open/world1/tmr/hasake/senlin13.c

inherit ROOM;

void create()
{
	set("short", "針葉林");
	set("long", @LONG
這是極西天山腳下的一片針葉林，林中鳥獸成群，滿地鋪蓋著厚厚一
層鬆針。西北方的一座高聳的山脈便是天山了，山上終年積雪，山下卻是
綠樹成蔭。往東南走便是大草原，有辛勤的哈薩克族人在那裡放牧。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"senlin3",
]));
		set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wolf2" : 3,
  __DIR__"npc/wolf3" : 1,
]));

	setup();
	replace_program(ROOM);
}
