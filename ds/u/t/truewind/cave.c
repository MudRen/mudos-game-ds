// Room: /u/t/truewind/cave.c

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
這是風清揚平時居住棲身的山洞，洞內除了幾樣簡單的家當外，
可說是空空蕩蕩，什麼都沒有。角落裡躺著幾件風清揚的衣服，附近
還有生過火的餘燼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"workroom",
]));
	set("no_clean_up", 0);
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
