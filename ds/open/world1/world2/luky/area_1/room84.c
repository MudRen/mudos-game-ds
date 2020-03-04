// Modify with AreaMaker1.0
// Room84.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
從這裡就能聞到湖水的味道，西邊不遠處可以看到一片湖泊。這
裡風光明媚，是個渡假休閒的好地方。
LONG
	);
	set("exits", ([
		"north": __DIR__"room74",
		"east": __DIR__"room85",
		"south": __DIR__"room94",
		"west": __DIR__"room83",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

