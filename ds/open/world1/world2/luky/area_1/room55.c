// Modify with AreaMaker1.0
// Room55.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
這裡是哪裡你也不太清楚，東邊有個池塘擋住了你的去路。你看
到池塘上漂了一個破舊的漱口杯，上面還有一隻小不點的蝸牛正在上
面隨杯漂流著，感覺十分悲慘淒涼。
LONG
	);
	set("exits", ([
		"north": __DIR__"room45",
		"south": __DIR__"room65",
		"west": __DIR__"room54",
		"northeast": __DIR__"room46",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

