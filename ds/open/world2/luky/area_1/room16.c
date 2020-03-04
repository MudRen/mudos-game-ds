// Modify with AreaMaker1.0
// Room16.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
一走進這裡北方的高山立刻硬入眼簾。四周到處都是大樹，滿地
的雜草和枯葉，因為這裡的樹葉濃密，所以有些潮濕。西邊的雜草長
的比人還高，以至於你無法看清那邊有什麼東西。
LONG
	);
	set("exits", ([
		"east": __DIR__"room17",
		"south": __DIR__"room26",
	]));
	set("hide_exits", ([
		"west": __DIR__"room15",
 	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

