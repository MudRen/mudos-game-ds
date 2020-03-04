// Room: /tmr/future/hunter_forest/hole9.c

inherit ROOM;

void create()
{
	set("short", "山洞裡");
	set("long", @LONG
你正處在一個山洞裡，伸手不見五指的黑暗，使得你只得邊摸著牆壁
邊行走，你只覺得你現在所處的通道頗為廣敝。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "north" : __DIR__"hole8",
	  "south" : __DIR__"hole4",
	]));
	set("no_clean_up", 0);
	set("world", "future");
	set("light",1);
	setup();
	replace_program(ROOM);
}
