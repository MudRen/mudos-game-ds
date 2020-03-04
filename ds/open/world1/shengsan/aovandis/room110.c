// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"植物園"NOR);
	set("long", @LONG
絡繹不絕的遊客在這觀賞這裡的一草一木，不時你會看到孩童的嬉鬧
聲穿梭期間，美麗的花朵和植物在走到的兩旁，每三五步就有一棵長直的
大樹。亮麗的陽光照射在油亮的綠色植物上，好不美麗啊。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"room112",
	    "west" : __DIR__"room050",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

