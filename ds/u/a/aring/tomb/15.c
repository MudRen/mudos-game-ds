// Room: /u/a/aring/tomb/15.c

inherit ROOM;

void create()
{
	set("short", "current_light 0");
	set("long", @LONG
你正站在一座墳墓的上頭，這裡雜草叢生，四周還有一些被動物
挖掘的坑洞，不小心腳還會陷到土裡去。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"16.c",
  "south" : __DIR__"14.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
