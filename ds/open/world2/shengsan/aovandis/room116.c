// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"植物園"NOR);
	set("long", @LONG
亮麗的陽光照射在油亮的綠色植物上，各式各樣的植物全在你的眼底
下了，你看到有許多可愛的小生物在其中玩耍鬥樂。踏在地上的石磚之上
，聽著鳥叫蟲鳴，你想這就是人生一大快事阿！
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room117",
	    "south": __DIR__"room118",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird0.c" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

