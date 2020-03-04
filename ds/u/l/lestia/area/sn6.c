// Room: /u/l/lestia/area/sn6.c

inherit ROOM;

void create()
{
 set("short", "北方大森林");
	set("long", @LONG

你走進一片陰暗的森林中，這條小徑除了你之外沒有其他的人或動物，
幾棵高大的樹木上長滿了樹鬚，從樹枝上垂在你的面前，你深深的吸
了一口氣，加緊腳步往前走去。

LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("world", "undefine");
set("objects", ([ 
__DIR__"npc/bear":2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"sn5",
  "down" : __DIR__"sn7",
]));

	setup();
	replace_program(ROOM);
}
