// Room: /u/b/bennyng/area/room35.c

inherit ROOM;

void create()
{
	set("short", "吊橋上");
	set("long", @LONG
這是一條剛修好的吊橋，往下看一看，你的心也快要跳出來．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room36",
  "north" : __DIR__"room34",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
