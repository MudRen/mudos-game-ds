// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "正興街");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("outdoor","land");
	set("light",1);
	set("exits", ([
	"north": __DIR__"eega25",
	"south": __DIR__"eega40",
	]));
	setup();
	replace_program(ROOM);
}
