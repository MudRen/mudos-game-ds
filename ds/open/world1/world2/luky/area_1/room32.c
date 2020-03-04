// Modify with AreaMaker1.0
// Room32.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
這裡是一片人煙稀少的樹林。樹葉非常茂密，即使是白天也很難
看到陽光。南邊有一棵巨大的老榕樹，上面還有個蜂窩，可是附近並
沒有看到花可採蜜，不知道牠們是靠什麼維生的。  
LONG
	);
	set("exits", ([
	        "north": __DIR__"room22",
		"east": __DIR__"room33",
		"south": __DIR__"room42",
		"west": __DIR__"room31",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

