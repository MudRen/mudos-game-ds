// Room: /open/world1/tmr/north_forest/cave2e.c

inherit ROOM;

void create()
{
	set("short", "地底洞穴");
	set("long", @LONG
你正處在一個地底洞穴中，由於陽光無法照射進來，所以四週盡是黑漆
漆的一切，你只能勉強順著岩壁往前進。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 5);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/troll5" : 2,
  __DIR__"npc/troll4" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cave2en",
  "west" : __DIR__"cave2",
]));

	setup();
	replace_program(ROOM);
}
