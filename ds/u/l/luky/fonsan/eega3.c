
inherit ROOM;

void create()
{
	set("short", "五甲路");
	set("long", "這是一間什麼也沒有的空房間。\n");
	set("outdoor","land");
	set("exits", ([
	"north": __DIR__"eega2",
	]));
	setup();
	replace_program(ROOM);
}
