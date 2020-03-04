// Modify with AreaMaker1.0
// Room22.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在樹林裡，這裡的草長的比較低一些。微風輕吹，樹葉發
出一陣沙沙沙的聲音。這裡的自然景觀十分豐富，現在已經很難看到
這麼自然的景色了。
LONG
	);
	set("exits", ([
	        "south": __DIR__"room32",
		"north": __DIR__"room12",
		"east": __DIR__"room23",
		"west": __DIR__"room21",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

