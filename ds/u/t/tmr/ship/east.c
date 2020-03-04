// Room: /tmr/ship/1.c

inherit ROOM;

void create()
{
	set("short", "東渡口");
	set("long", @LONG
這是一個位於Ｘ縣的東渡口。
LONG
	);
	set("objects",([
		__DIR__"shipman":1,
	]) );

	set("no_kill",1);
	set("no_magic",1);
	set("no_clean_up", 0);
	
	setup();
}
