// Room2.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在濃密的樹林裡，這裡的草長到你的膝蓋這麼高。你的北
方和西方全是陡峭的山壁，林間不時傳來鳥獸求偶所發出的的美妙聲
音。
LONG
	);
	set("exits", ([
		"east": __DIR__"room3",
		"south": __DIR__"room12",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird0" : 3,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

