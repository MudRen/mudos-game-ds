// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "正義街");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("outdoor","land");
	set("exits", ([
	"north": __DIR__"eega42",
	"south": __DIR__"eega52",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
