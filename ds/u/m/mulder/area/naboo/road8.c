// Room: /u/s/sonicct/area/road8.c

inherit ROOM;

void create()
{
	set("short", "Naboo廣場中心");
	set("long", @LONG
這是Naboo城的廣場中心，這是Naboo城的市民經常來的地方。
遠看在噴水池的附近一對情侶正在溫馨中，和一班正在下棋的老人
，而這裡往東行可以走到Naboo城的大森林。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road9",
  "north" : __DIR__"road18",
  "west" : __DIR__"road7",
  "south" : __DIR__"road19",
]));
		 set("objects",([
  __DIR__"npc/beauty":1,
__DIR__"npc/child":2,
__DIR__"npc/citizen":2,
 ]));

	set("outdoors","road");
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
