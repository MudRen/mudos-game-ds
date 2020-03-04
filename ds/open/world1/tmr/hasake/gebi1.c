// Room: /open/world1/tmr/hasake/gebi1.c

inherit ROOM;

void create()
{
	set("short", "西域大戈壁");
	set("long", @LONG
這是西域的大戈壁，要走出這裡並非易事。不遠處塵土沙粒鋪天蓋
地般吹來，看來要起風暴了。
LONG
	);
	set("current_light", 1);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/world1/tmr/dragoncity/westgate2",
  "west" : __DIR__"gebi2",
]));

	setup();
	replace_program(ROOM);
}
