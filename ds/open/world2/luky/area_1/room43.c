// Modify with AreaMaker1.0
// Room43.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
這附近的的景色看起來都一模一樣，除了樹，就是草，如果是外
地來的旅客，很可能會因此而迷路。涼爽的微風從東方迎面吹來，讓
人有點昏昏欲睡。
LONG
	);
	set("exits", ([
		"north": __DIR__"room33",
		"east": __DIR__"room44",
		"south": __DIR__"room53",
		"west": __DIR__"room42",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

