// Room: /u/l/lestia/area/map_8_2.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-廂房走道");
	set("long", @LONG

一條用檜木所建造的走道在你腳下被你踩的咚咚作響，彷彿在抗議著你
前進的腳步太沉重，吵到在廂房休息的貴賓們，後方通往靈幻教的大殿後廳
，前方則是走道。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_8_3",
  "north" : __DIR__"map_7_2",
  "south" : __DIR__"map_9_2",
]));

	setup();
	replace_program(ROOM);
}
