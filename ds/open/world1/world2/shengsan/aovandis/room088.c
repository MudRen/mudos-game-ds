// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"上層走道"NOR);
	set("long", @LONG
一家一家的店面，分列在這條鑲著各種炫麗琉璃的石階之兩側，造型
劃一的店面招牌懸掛在這條商街的兩側。你可以看到有好多好多的市民在
這裡逛街。從這往西走是間規模頗大的百貨公司，往東則是間銀行。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room093",
	    "west" : __DIR__"room092",
	    "south": __DIR__"room089",
	    "north": __DIR__"room082",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}