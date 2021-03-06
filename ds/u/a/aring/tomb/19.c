// Room: /u/a/aring/tomb/19.c

inherit ROOM;

void create()
{
	set("short", "大墓園－墳墓");
	set("long", @LONG
你正站在一座墳墓的上頭，墳上半倒的十字架上刻有"無名傭兵之墓"，
上面還掛著一頂破爛的頭盔... 葬在這種地方，可能死後也會不得安寧吧。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"18.c",
  "west" : __DIR__"20.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
