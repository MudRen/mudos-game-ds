// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"上層走道"NOR);
	set("long", @LONG
你站在一排排往北而上的石階之上，石階上鑲著各種炫麗的琉璃，所
排出的圖騰樣式讓人匪夷所思。你可以清楚的看到有相當的人潮在這裡通
過，這裡是一個市內的商業區。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"room024",
	    "north": __DIR__"room088",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}