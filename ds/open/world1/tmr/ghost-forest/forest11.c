// Room: /tmr/garea/forest11.c

inherit ROOM;

void create()
{
	set("short", "霧中小路");
	set("long", @LONG
你正走在一條林中的小路，四週彌漫著一片淡霧，還透著一絲寒氣，
看到的景物盡是霧茫茫的看不甚清楚，往南迷霧深處瞧去，更慘白一片，
只怕走得進去，找不到路出來...
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
        "southwest" : __DIR__"forest9",
	  "northeast" : __DIR__"forest13",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
