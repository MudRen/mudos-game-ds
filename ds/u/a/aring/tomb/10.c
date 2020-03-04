// Room: /u/a/aring/tomb/10.c

inherit ROOM;

void create()
{
	set("short", "大墓園－墳墓");
	set("long", @LONG
你正站在一座墳墓的上頭，這裡散落著一些損壞的武器，也沒看到
墓碑，可能是被草草埋葬的。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"11.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
