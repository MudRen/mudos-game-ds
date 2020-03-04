// Room: /u/d/darkfool/area1/31.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
這裡是鎮上有點偏南的一條街道，你看到前方的道路是往東向延伸過
去的，鎮上知名的一間圖書館似乎在這附近有路可以轉進去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"32",
  "northwest" : __DIR__"c1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
