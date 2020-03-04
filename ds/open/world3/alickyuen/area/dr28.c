// Room: /u/a/alickyuen/area/dr28.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
這裡附近的房間都是供給醫生、護士工作之後休息一下，當中更會有
一些床，給他們在繁忙的工作中小睡一會。還有就是一些消閒的設備，如
電視、按摩椅等，令你恨不得進去小休一會。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"dr29",
  "north" : __DIR__"dr27",
  "enter" : __DIR__"dr31",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
