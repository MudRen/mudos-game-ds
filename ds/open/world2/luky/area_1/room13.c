// Modify with AreaMaker1.0
// Room13.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在樹林中。遠離大都市的塵囂，倘佯在大自然中的感覺令
人換然一新。東邊草叢似乎有一條小路，不過因為雜草太長了很難看
清楚。
LONG
	);
	set("exits", ([
		"north": __DIR__"room3",
		"south": __DIR__"room23",
		"west": __DIR__"room12",
	]));
	set("hide_exits", ([
		"east": __DIR__"room14",
 	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

