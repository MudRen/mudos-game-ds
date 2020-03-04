// Modify with AreaMaker1.0
// Room73.c

inherit ROOM;

void create()
{
	set("short","湖畔");
	set("long", @LONG
這裡是依莉莎湖的東北角。湖邊有許多的花草，還有一些小垃圾
，應該是從湖的另一邊漂流過來的。
LONG
	);
	set("exits", ([
		"north": __DIR__"room63",
		"east": __DIR__"room74",
		"south": __DIR__"room83",
		"west": __DIR__"room72",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird0" : 4,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

