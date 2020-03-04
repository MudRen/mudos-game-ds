// Modify with AreaMaker1.0
// Room18.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
到處都是高大的樹木，你發現這裡的風很強，連樹上的葉子幾乎
都被吹的一片也沒有了。
LONG
	);
	set("exits", ([
		"east": __DIR__"room19",
		"south": __DIR__"room28",
		"west": __DIR__"room17",
		"northeast": __DIR__"room9",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}


int valid_leave(object me, string dir)
{
	if( dir=="northeast" )
		return notify_fail("那裡的風太強了以至於你無法走過去。\n");
	return ::valid_leave(me, dir);
}
