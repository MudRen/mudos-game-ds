// Modify with AreaMaker1.0
// Room70.c

inherit ROOM;

void create()
{
	set("short","大草原");
	set("long", @LONG
這裡是一片大草原，四處都是綠油油的芳草。青草的味道讓人有
股淡薄名利的感覺，人生最幸福之事莫過於單純的生活了。
LONG
	);
	set("exits", ([
		"north": __DIR__"room60",
		"south": __DIR__"room80",
		"west": __DIR__"room69",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/spider0" : 2,
		__DIR__"npc/pig0" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","land");	
	setup();
	replace_program(ROOM);
}

