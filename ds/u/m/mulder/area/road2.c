// Room: /u/m/mulder/area/road2.c

inherit ROOM;

void create()
{
	set("short", "新彼得城-廣場大道");
	set("long", @LONG
經過旅店大街之後，你就走到了廣場大道．你看見很多不同
的時空漂泊者在這�婺g過或是在談天交易心得．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road1",
  "north" : __DIR__"road3",
]));
	set("shot", "新彼得城 - 廣場大街");
set("outdoors", "road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
