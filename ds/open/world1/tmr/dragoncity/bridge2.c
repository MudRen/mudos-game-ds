// Room: /open/world1/tmr/dragoncity/bridge2.c

inherit ROOM;

void create()
{
	set("short", "磐龍城-護城大橋");
	set("long", @LONG
你正走在磐龍城的護城大橋，這是一條長約百來尺，寬約十尺的
大橋，正橫跨了護城河與磐龍城門口之間。每日有不少馬車、商人、
旅客來回穿梭，顯得非常熱鬧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge1",
  "north" : __DIR__"bridge3",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
