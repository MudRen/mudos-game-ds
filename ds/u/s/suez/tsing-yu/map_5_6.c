// Room: /u/s/suez/tsing-yu/map_5_6.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
    這裡是皴玉古城的北端，再往北經過峽道出去便是連通皇城及步靈的
官道，所以此地可說是皴玉古城的咽喉要地。只見西邊是皴玉古城的衙門
，東邊是官府設立的錢莊，聽說衙門之後還有軍營，看起來這附近的黑虎
寨非同小可，才讓這裡戒備如此森嚴。但是由於進來的路只有這一條，所
以其他地方似乎祥和許多。你看到峽道口旁立了一塊碑，似乎在憑弔那些
當時死去的上千英魂。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"map_4_6",
  "east" : __DIR__"map_5_7",
  "west" : __DIR__"map_5_5",
  "south" : __DIR__"map_6_6",
]));

	setup();
	replace_program(ROOM);
}
