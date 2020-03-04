// Room: /u/a/acme/area2/t50.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下四層]");
	set("long", @LONG
你的眼前一亮，這裡燈火通明，刺得你眼睛睜不見來，四周空無
一物，只見石牆上有個小油燈，並沒有特別的地方。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ju" : 1,
  __DIR__"npc/xie" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"t51",
  "south" : __DIR__"t48",
]));
set("light",1);
	set("no_clean_up", 0);

	setup();
}
