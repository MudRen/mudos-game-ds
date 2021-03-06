// Room: /open/world1/tmr/goat_maze/maze14.c

inherit ROOM;

void create()
{
	set("short", "羊男的迷宮 - 石牆路");
	set("long", @LONG
你正走在一個以石頭牆圍成的迷宮，似乎是幾千年前就建在這森林之
中。綠色的青苔及花草爬滿了四週一堵又一堵的石牆，與森林自然而然地
融合在一起。你雖然身處在迷宮之中，但是倒也不急著想要離開。
LONG
	);
	set("shrot", "羊男的迷宮 - 石牆路");
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/bariour4" : 4,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"maze11",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
