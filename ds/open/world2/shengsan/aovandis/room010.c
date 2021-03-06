// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"中心廣場東側"NOR);
	set("long", @LONG
寬闊廣場裡的地上是由各種顏色的琉璃所砌成的，每天早晨首先迎接
陽光的就是這些美麗的琉璃磚了。你正在奧凡迪斯中心廣場的東側，往東
直走就是東城門了，往南就是守衛隊總司令辦公室。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room011",
	    "west" : __DIR__"room001",
	    "south": __DIR__"room060",
	    "north": __DIR__"room058",
            ]));
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/bird2" : 4,
        ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}