// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"中心廣場的北方"NOR);
	set("long", @LONG
你在廣場的北方，地上鑲著各種炫麗的琉璃，所排出的圖騰樣式讓人
匪夷所思，但你不得不贊嘆城市的美麗。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room058",
	    "west" : __DIR__"room057",
	    "south": __DIR__"room001",
	    "north": __DIR__"room043",
            ]));
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/bird2" : 3,
        ]));
	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}