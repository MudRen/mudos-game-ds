// Room: /future/area/digging_road1.c

inherit ROOM;

void create()
{
	set("short", "礦區道路");
	set("long", @LONG
你正走在礦區裡的一條道路，西邊有間規模已為陳舊的酒館，從這就
可聽到非常頂沸的人聲，看得出來酒館裡非常的熱鬧，往東望去可看到一
間頗為大間的工廠，為當地的煤鐵加工廠。往北走去可到達採礦區。
LONG
	);
	set("world", "future");
	set("exits", ([ /* sizeof() == 3 */
	  "north" : __DIR__"digging_road4",
	  "west" : __DIR__"hotel",
	  "east" : __DIR__"digging_road2",
	]));
	set("outdoors","desert");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
