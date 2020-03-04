// Room: /u/k/king/area/r1.c

#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIR "戰國"HIY"皇陵"NOR"-不歸冥路");
	set("long", @LONG
這是一條彎曲的小路，但是氣氛異常的寒冷，四周充滿了殺機，忽然
從天上掉落一顆人頭，讓你感到毛骨悚然，沒有實力還是快離開吧。這邊
不是普遍人可以來的。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r2",
  "south" : __DIR__"r2.c",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bat" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
