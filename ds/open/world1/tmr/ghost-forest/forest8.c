// Room: /open/world1/tmr/ghost-forest/forest8.c

inherit ROOM;

void create()
{
	set("short", "小徑");
	set("long", @LONG
這是一條頗不成路的小徑，其路狹隘不過數步，行走其間，倒不如說
是在樹與樹之間的空隙行走，望西南方不遠處可看到處空地，如果走累了
，倒不妨到那略事休息，再行趕路。
LONG
	);
	set("world", "past");
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"forest9",
  "southwest" : __DIR__"forest6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
