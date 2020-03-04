// Modify with AreaMaker1.0
// Room45.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你走到這裡不禁覺得有點累了，旁邊剛好有個石頭可以讓你休息
一下。北邊的大樹旁長了一堆雜草，附近還有些廢棄的飲料罐，真希
望附近就有便利商店可以買些飲料來解解渴。
LONG
	);
	set("exits", ([
		"east": __DIR__"room46",
		"south": __DIR__"room55",
		"west": __DIR__"room44",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

