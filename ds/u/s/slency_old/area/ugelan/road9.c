// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
一條青石鋪成的街道，人群熙來攘往，街道上有不少的鴿子在地上
走步，也有些人坐在街旁撒著米粒給鴿子吃，街道中央有個小池子，清
涼的泉水從中不斷冒出，供路人解渴之用，由這裡往東往北都是一條人
來人往的街道。	
LONG
);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road10",
  "east" : __DIR__"road8",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}