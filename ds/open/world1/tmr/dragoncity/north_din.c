// Room: /open/world1/tmr/dragoncity/north_din.c

inherit ROOM;

void create()
{
	set("short", "丁字街");
	set("long", @LONG
這裡是磐龍城北部的丁字街口。向北一直通向玄武門，
東面和西面是一條筆直的青石大街，通向城內。南面是一堵
上蓋紅色琉璃瓦的高牆，裡面是少帥軍統帥寇仲的府邸。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"northroad2",
  "east" : __DIR__"northroad1",
  "north" : __DIR__"north1",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
