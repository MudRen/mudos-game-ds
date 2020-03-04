// Room: /u/s/sonicct/area/road5.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
這裡開始屬於皇宮的範圍，守衛不停在你身旁走過。令你有
一種特別的感覺。往東走可以到市集，購買你所需的物品。往西
可以通往花園。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road17",
  "west" : __DIR__"road16",
  "north" : __DIR__"road6",
  "south" : __DIR__"road4",
]));
		 set("objects",([
  __DIR__"npc/citizen":1,
 ]));

	set("outdoors","road");
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
