// Modify with AreaMaker1.0
// Room31.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在濃密的樹林裡，這裡的草長到你的膝蓋這麼高。南方有
棵巨大的榕樹，還垂下了許多又長又密的氣根，林間不時傳來鳥獸求
偶所發出的的美妙聲音。
LONG
	);
	set("exits", ([
		"north": __DIR__"room21",
		"east": __DIR__"room32",
		"southeast": __DIR__"room42",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/spider0" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

