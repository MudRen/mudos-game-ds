// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"異教徒禮堂"NOR);
	set("long", @LONG
窗口透射進微弱的光線照射在你的周圍，兩旁的長桌之上擺放著你看
不懂的物品，很奇特，也很細膩。南邊的牆角還有一座小型的水池，水池
上有個水車不停的受到由上而下的細細水流牽引而轉動。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room088",
	    "west" : __DIR__"room099",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}