// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"奧凡大道"NOR);
	set("long", @LONG
你在奧凡迪斯的奧凡大道上，這條大道是位於城裡的西半邊，往西直
走就是西城門了。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room024",
	    "west" : __DIR__"room020",
	    "south": __DIR__"room073",
	    "north": __DIR__"room086",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}