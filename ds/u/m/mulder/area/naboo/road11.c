// Room: /u/s/sonicct/area/road11.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
離遠了市中心，你發現這裡有兩條小路，通往不同的地方。
你突然在好奇心之下停在這裡，看看那兩條小路是通去那裡的。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road10",
  "north" : __DIR__"road15",
  "west" : __DIR__"road12",
//  "south" : __DIR__"road14",
]));
		 set("objects",([
  __DIR__"npc/citizen":1,
 ]));

	set("outdoors","road");
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
