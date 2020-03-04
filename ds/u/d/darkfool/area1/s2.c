// Room: /u/d/darkfool/area1/s2.c

inherit ROOM;

void create()
{
	set("short", "南住宅區街道");
	set("long", @LONG
你位在住宅區內部深入了一些的地方，左右兩旁的速成屋型式不
一但仍是大同小異，並沒有什麼值得特別注意的。往內的街道是向南
延伸過去。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"s1",
  "south" : __DIR__"s3",
]));

	setup();
	replace_program(ROOM);
}
