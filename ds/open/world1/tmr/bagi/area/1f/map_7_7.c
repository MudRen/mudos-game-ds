// Room: /open/world1/tmr/bagi/area/1f/map_7_7.c

inherit ROOM;

void create()
{
	set("short", "寒日洞一層");
	set("long", @LONG
四週的岩漿不斷地沸騰的，洞內的溫度一直居高不下，熱的人都快昏
頭了。在石道上有處往下的洞穴。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "down" : "/open/world1/tmr/bagi/area/2f/map_2_2",
  "southeast" : __DIR__"map_8_8",
  "southwest" : __DIR__"map_8_6",
  "northeast" : __DIR__"map_6_8",
  "northwest" : __DIR__"map_6_6",
]));
	set("map_long", 1);
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
