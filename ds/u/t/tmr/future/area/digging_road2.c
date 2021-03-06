// Room: /future/area/digging_road2.c

inherit ROOM;

void create()
{
	set("short", "礦區道路");
	set("long", @LONG
你正在礦區的一條路上，往南走去是間極大的工廠，為「主城」指派
專司這個礦區的大小事宜，也是此地唯一能工作的地方，往東走去是當地
礦工居住的房屋。
LONG
	);
	set("world", "future");
	set("outdoors","desert");
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"stihy",
	  "west" : __DIR__"digging_road1",
	  "east" : __DIR__"digging_road3",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
