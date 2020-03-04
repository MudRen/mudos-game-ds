inherit ROOM;

void create()
{
	set("short", "小徑");
	set("long", @LONG
這裡是一片大平原中的小徑，雖然說是小徑，但是因為小徑上叢
生的雜草，讓你有點搞不清楚究竟是不是走在正確的路上。在遠遠的
東邊可以看見一大片樹林。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"path2",
	]));

	setup();
	replace_program(ROOM);
}
