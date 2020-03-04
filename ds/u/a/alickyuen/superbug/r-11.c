// Room: /u/s/superbug/train/r-3.c

inherit ROOM;

void create()
{
	set("short", "鐵路內部");
	set("long", @LONG
你忽然發現周圍陷入一片黑暗之內，除了斷斷續續的滴水聲，你聽不
到任何的聲音，彷彿掉進了黑暗的世界之內，你只能沿著鐵軌行走，以免
在黑暗中迷失方向。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r-5.c",
  "east" : __DIR__"r-12.c",
]));
set("objects", ([
__DIR__"npc/guard2" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
