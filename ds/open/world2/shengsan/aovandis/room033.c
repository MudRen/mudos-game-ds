// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"西側城門"NOR);
	set("long", @LONG
你在奧凡迪斯的西側城門裡，堅實的城牆就在你的身旁，城牆是由少
有的強韌琉璃所建造而成，具有相當的防禦能力，外表似乎有一些被打過
的痕跡，這說明了這裡似乎曾經發生過衝突。如果你要出城(out)，別忘了
跟守衛打打招呼喔。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room026",
	    "out":   "/open/world2/mainland1/map_22_26",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/gateguard" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
