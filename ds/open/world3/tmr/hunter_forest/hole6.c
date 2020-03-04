// Room: /tmr/future/hunter_forest/hole6.c

inherit ROOM;

void create()
{
	set("short", "山洞裡");
	set("long", @LONG
你正處在一個山洞裡，伸手不見五指的黑暗，使得你只得邊摸著牆壁
邊行走，四周越來越黑的黑暗，以及混濁的空氣直讓你覺得透不過氣來。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"hole5",
	  "east" : __DIR__"hole7",
	]));
	set("no_clean_up", 0);
	set("world", "future");
	set("light",1);
	setup();
	replace_program(ROOM);
}
