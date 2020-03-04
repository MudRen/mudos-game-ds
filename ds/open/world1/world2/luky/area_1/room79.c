// Modify with AreaMaker1.0
// Room79.c

inherit ROOM;

void create()
{
	set("short","大草原");
	set("long", @LONG
這裡是一片大草原。草隨著風搖晃著，就像是海面上的波浪一般
。西邊不遠處似乎有個水池，西北方則是一片茂盛的樹林。微風從北
方吹來，十分舒適。
LONG
	);
	set("exits", ([
		"north": __DIR__"room69",
		"east": __DIR__"room80",
		"west": __DIR__"room78",
		"southwest": __DIR__"room88",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}

