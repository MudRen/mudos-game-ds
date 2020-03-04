// Room: /u/a/alickyuen/area/zoo12.c
//update by alickyuen 9/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Secret＠CyberZoo"NOR);
	set("long", @LONG
好不容易才走出了這個草叢迷宮，你暗舒了一口氣，總算走得出來了
。你現身處在草叢堆中，四處看看後，你發現南邊有一些微弱的光。看來
是出口，碰碰運氣吧﹗
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoo13",
  "out" : __DIR__"zoo11",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
