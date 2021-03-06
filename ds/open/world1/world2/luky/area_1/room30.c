// Modify with AreaMaker1.0
// Room30.c

inherit ROOM;

void create()
{
	set("short","風之原");
	set("long", @LONG
這裡是風之平原的東北角，你的西邊是一大片樹林。這裡一年四
季都吹著強勁的狂風，由於強風中夾雜了熱氣，所以許多植物都無法
在這裡生長，在這裡你必須低著頭才能勉強張開眼睛。
LONG
	);
	set("exits", ([
		"north": __DIR__"room20",
		"west": __DIR__"room29",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir=="north" )
		return notify_fail("那裡的風太強了以至於你無法走過去。\n");
	return ::valid_leave(me, dir);
}
