// Room: /u/l/lestia/area/sn12.c

inherit ROOM;

void create()
{
	set("short", "北方大森林-小徑");
	set("long", @LONG

你走進一片陰暗的森林中，這條小徑除了你之外沒有其他的人或動物，
幾棵高大的樹木上長滿了樹鬚，從樹枝上垂在你的面前，你深深的吸
了一口氣，加緊腳步往前走去。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn11",
  "south" : __DIR__"sn13",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
