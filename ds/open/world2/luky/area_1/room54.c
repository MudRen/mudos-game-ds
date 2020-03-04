// Modify with AreaMaker1.0
// Room54.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你的南邊有棵樹，你看到北邊不遠處有一棵高聳入雲的大樹。到
處都是綠油油一片，處處充滿了生機。
LONG
	);
	set("exits", ([
		"east": __DIR__"room55",
		"west": __DIR__"room53",
		"southeast": __DIR__"room65",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

