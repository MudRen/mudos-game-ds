// Modify with AreaMaker1.0
// Room46.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在濃密的樹林裡，這裡的草長到你的膝蓋這麼高。南方還
有個小池塘。
LONG
	);
	set("exits", ([
		"north": __DIR__"room36",
		"east": __DIR__"room47",
		"west": __DIR__"room45",
		"southwest": __DIR__"room55",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

