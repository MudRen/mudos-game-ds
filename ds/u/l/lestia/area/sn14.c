// Room: /u/l/lestia/area/sn14.c

inherit ROOM;

void create()
{
	set("short", "北方大森林-小徑");
	set("long", @LONG

再往前走就接近傳說中靈幻教的所在地了，你看不出來這裡有著什麼森
嚴的守備或讓人害怕的地方，你始終想不透為什麼進入的人總是有去無出，
你為了滿足你好奇的心，毅然的往前繼續走去。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sn15",
  "north" : __DIR__"sn13",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
