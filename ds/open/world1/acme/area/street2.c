// Room: /u/a/acme/area/street2.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
這是一條頗為寬敞的街道，人潮擁擠、摩頂放踵，只聽著街販叫賣聲
此起彼落，參雜著過往人群的喧嘩聲，不禁令人贊嘆此地的繁華。往西可
出城，北邊不遠處有一間當鋪。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"wynd",
  "west" : __DIR__"wdoor",
  "east" : __DIR__"st",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
	replace_program(ROOM);
}
