// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"東側城門"NOR);
	set("long", @LONG
這裡是奧凡迪斯的東側城門，純樸的市民常常在這裡進進出出，好快
樂，也好自然。這裡雖然是側門，但其堅實度卻也不比其他的城門來的遜
色，甚至有過之而無不及。如果你要出城(out)，別忘了跟守衛打招呼喔。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room015",
	    "out"  : "/open/world2/mainland1/map_22_28",
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
