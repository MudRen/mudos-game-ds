// Room: /u/d/darkfool/area1/s3.c

inherit ROOM;

void create()
{
	set("short", "南住宅區街道");
	set("long", @LONG
這裡是住宅區的某個角落，西邊的小屋看來不怎麼起眼，但不時
有居民們抱著看來應該是採礦用的工具在進進出出。南邊也有間引人
注目的房子，純白的外觀，雖然也是速成屋但似乎有種更為典雅的氣
息。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"shop2",
  "north" : __DIR__"s2",
  "south" : __DIR__"doctor",
]));

	setup();
	replace_program(ROOM);
}
