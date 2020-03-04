// Room: /u/a/acme/area/pass3.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你正走在一條蜿蜒的山路上，山路甚是崎嶇，滿地盡是枯黃的落葉，
南邊可望見綠油油的稻田，往東可通往天城。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pass4",
  "south" : __DIR__"farm",
  "east" : __DIR__"pass2",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
