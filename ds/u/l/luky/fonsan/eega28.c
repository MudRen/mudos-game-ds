// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "南昌街");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("outdoor","land");
	set("exits", ([
	"east": __DIR__"eega29",
	"west": __DIR__"eega27",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
