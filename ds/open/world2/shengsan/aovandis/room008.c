// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"寬廣的走道"NOR);
	set("long", @LONG
你在一個寬廣走道上，走道上鑲著各種炫麗的琉璃，所排出的圖騰樣
式讓人匪夷所思，但你不得不贊嘆城市的美麗，往北直走可到達城市的中
心地帶，往南直走是城市的正城門，東西方為守衛的辦公室。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room036",
	    "west" : __DIR__"room039",
	    "south": __DIR__"room009",
	    "north": __DIR__"room007",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}