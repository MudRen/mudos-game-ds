// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"警備隊辦公室"NOR);
	set("long", @LONG
你看到牆壁上掛著好多的警徽，相當的引人注目，可以看出這些警備
隊的隊員都是充滿榮譽感的好警衛。他們的工作就是巡邏城裡，維持城裡
的安寧及秩序。他們正在辦公桌上辦公著。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room037",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/patrol" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}