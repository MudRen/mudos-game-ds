// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"中心廣場西側"NOR);
	set("long", @LONG
好多面帶笑容的市民在這個廣場活動，有時你會看到兒童在人群中奔
跑玩耍，有時你會看到面帶滑稽的小丑在耍特技，有時你又會看到熱戀中
的情侶手拉著手在長椅上坐著。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room001",
	    "west" : __DIR__"room024",
	    "south": __DIR__"room059",
	    "north": __DIR__"room057",
            ]));

	set("light", 1);

	setup();
	replace_program(ROOM);
}