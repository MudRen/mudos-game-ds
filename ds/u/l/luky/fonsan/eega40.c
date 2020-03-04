// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "正興街轉南昌街口");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("outdoor","land");
	set("exits", ([
	"west": __DIR__"eega39",
	"south": __DIR__"eega45",
	"north": __DIR__"eega26",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
