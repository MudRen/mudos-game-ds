// Modify with AreaMaker1.0
// Room21.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
這裡也是一大片的樹林，到處都是雜草和腐葉。微微的風徐徐的
吹著，令人感到非常舒服。
LONG
	);
	set("exits", ([
		"north": __DIR__"room11",
		"east": __DIR__"room22",
		"south": __DIR__"room31",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

