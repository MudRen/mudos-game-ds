// Modify with AreaMaker1.0
// Room12.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
這裡是樹林的內部深處，北方不遠處有一座雄偉的高山向東綿延
而去。地上有許多蕨類和雜草，附近的大樹有許多藤蔓攀爬其間，似
乎將全部的樹都連成一片了。
LONG
	);
	set("exits", ([
		"north": __DIR__"room2",
		"east": __DIR__"room13",
		"south": __DIR__"room22",
		"west": __DIR__"room11",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

