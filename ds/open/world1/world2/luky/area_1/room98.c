// Modify with AreaMaker1.0
// Room98.c

inherit ROOM;

void create()
{
	set("short","雜草堆");
	set("long", @LONG
你身在灌木林旁邊的一叢草堆中。這裡到處都是和你一樣高的草
，你根本看不清楚這裡有什麼出路。附近西方灌木林中似乎有一些細
微的聲音，不注意聽是很難發現的。
LONG
	);
	set("hide_exits", ([
		"north": __DIR__"room88",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/pig0" : 4,
		__DIR__"npc/pig2" : 1,
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

