// Room: /u/a/aring/tomb/17.c

inherit ROOM;

void create()
{
	set("short", "大墓園－墳墓");
	set("long", @LONG
你正站在一座墳墓的上頭，這裡雜草叢生，幾乎快看不出這裡有個
墳墓，草叢中不時有窸簌的騷動，一旁有個不大的小洞。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"18.c",
  "east" : __DIR__"16.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
