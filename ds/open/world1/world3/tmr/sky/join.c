// Room: /open/world3/tmr/sky/join.c

inherit ROOM;

void create()
{
	set("short", "報名處");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
