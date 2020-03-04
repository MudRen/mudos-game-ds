// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "正義街與南昌街交叉口");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("outdoor","land");
	set("exits", ([
	"north": __DIR__"eega24",
	"south": __DIR__"eega42",
	"east": __DIR__"eega30",
	"west": __DIR__"eega28",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
