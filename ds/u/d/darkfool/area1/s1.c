// Room: /u/d/darkfool/area1/s1.c

inherit ROOM;

void create()
{
	set("short", "南住宅區街道");
	set("long", @LONG
你走入了鎮南的住宅區，速成屋一個個井然有序地排列著向南擴
散過去，幾個居民與你擦身而過，好奇地打量著你這外來的陌生人，
據說小鎮上唯一的醫生就是住在這一區的某處。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"s2",
  "north" : __DIR__"c1",
]));

	setup();
	replace_program(ROOM);
}
