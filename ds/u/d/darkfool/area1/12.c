// Room: /u/d/darkfool/area1/12.c

inherit ROOM;

void create()
{
	set("short", "街道轉角");
	set("long", @LONG
這裡的街道旁有個轉角，通往鎮北的住宅區，東向的街道繼續往
東延伸了一小段距離。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"13",
  "west" : __DIR__"11",
  "north" : __DIR__"14",
]));

	setup();
	replace_program(ROOM);
}
