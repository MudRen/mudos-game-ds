// Modify with AreaMaker1.0
// Room94.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在一片樹林中。這裡因為靠湖所以有些潮濕。你看到旁邊
有個小墓碑，上面的字已經模糊不清了，只能勉強看到「雖死猶存」
四個字。
LONG
	);
	set("exits", ([
		"north": __DIR__"room84",
		"west": __DIR__"room93",
		"northeast": __DIR__"room85",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/spider2" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

