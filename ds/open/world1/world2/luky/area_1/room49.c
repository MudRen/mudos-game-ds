// Modify with AreaMaker1.0
// Room49.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
這裡的樹林顯的比較稀疏，似乎你已走到了樹林的邊緣。你可以
很清楚看到在你的西邊有一條平坦的小徑。你也可以看到兩排整齊的
樹豎立在小徑兩旁。東邊的草原仍然長得很茂盛。
LONG
	);
	set("exits", ([
		"north": __DIR__"room39",
		"south": __DIR__"room59",
		"southeast": __DIR__"room60",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

