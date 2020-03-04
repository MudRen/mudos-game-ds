// Modify with AreaMaker1.0
// Room75.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
旁邊有個小池塘，池塘旁邊有許多的水草。突然有隻小蟲，飛到
了你的鼻子上，正當你要拍牠的時候，又突然的飛走了。
LONG
	);
	set("exits", ([
		"north": __DIR__"room65",
		"south": __DIR__"room85",
		"west": __DIR__"room74",
		"southeast": __DIR__"room86",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 1,
		__DIR__"npc/pig1" : 2,
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

