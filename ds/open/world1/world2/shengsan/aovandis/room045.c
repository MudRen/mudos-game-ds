// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"寬廣的走道"NOR);
	set("long", @LONG
你站在一排排往北而上的石階之上，石階上鑲著各種炫麗的琉璃，所排出的圖騰
樣式讓人匪夷所思。從這往東直直走去可以到達奧凡迪斯著名的植物園，往西直直走
是美達崙學院。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room047",
	    "west" : __DIR__"room051",
	    "south": __DIR__"room044",
	    "north": __DIR__"room046",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
