// Modify with AreaMaker1.0
// Room23.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你的左右四周長滿了長長的草。東邊是一棵大榕樹，樹幹上還有
些小黑點動來動去，你走近一看，才發現是許多黑螞蟻正在辛勤的工
作著。
LONG
	);
	set("exits", ([
		"north": __DIR__"room13",
		"south": __DIR__"room33",
		"west": __DIR__"room22",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

