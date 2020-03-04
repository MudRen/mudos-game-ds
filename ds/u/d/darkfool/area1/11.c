// Room: /u/d/darkfool/area1/11.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
你正走在鎮上略偏北的一處街道上，幾個居民正親切的跟你打招
呼，往北方望去似乎是一大片住宅的樣子，東方街道盡頭有間看起來
有些特別的小屋。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"12",
  "southwest" : __DIR__"c1",
]));

	setup();
	replace_program(ROOM);
}
