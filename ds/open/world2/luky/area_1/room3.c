// Room3.c

inherit ROOM;

void create()
{
	set("short","樹林間");
	set("long", @LONG
這裡也是一大片的樹林，雜草幾乎比你的膝蓋還高。北方和東方
全是陡峭的山壁，以至於你無法繼續前進。微微的風徐徐的吹著，令
人感到非常舒服。
LONG
	);
	set("exits", ([
		"south": __DIR__"room13",
		"west": __DIR__"room2",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

