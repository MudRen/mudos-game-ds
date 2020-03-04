// Modify with AreaMaker1.0
// Room39.c

inherit ROOM;

void create()
{
	set("short","樹林邊");
	set("long", @LONG
你正走在樹林的邊緣。大風不斷的從東北方吹來，樹枝隨風搖曳
，發出一陣陣沙沙的聲音。東邊有個巨石擋住了往東的去路，西南方
似乎是一個草原。
LONG
	);
	set("exits", ([
		"north": __DIR__"room29",
		"south": __DIR__"room49",
		"southwest": __DIR__"room48",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

