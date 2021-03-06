// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"中心廣場東北邊"NOR);
	set("long", @LONG
你在廣場的東北方，地上鑲著各種炫麗的琉璃，所排出的圖騰樣式讓
人匪夷所思，但你不得不贊嘆城市的美麗。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room042",
	    "south": __DIR__"room020",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/sergeant" : 1,
	]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}