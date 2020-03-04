// Room: /u/a/aring/tomb/18.c

inherit ROOM;

void create()
{
	set("short", "大墓園－墳墓");
	set("long", @LONG
你正站在一座墳墓的上頭，這裡的地上被挖得亂七八糟，墳中的棺
木已經有一半裸露出來，透過棺蓋的縫隙看進去，棺材裡面竟然是空的。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"19.c",
  "east" : __DIR__"17.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
