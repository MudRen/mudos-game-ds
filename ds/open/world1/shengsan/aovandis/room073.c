// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"地圖店"NOR);
	set("long", @LONG
這裡有克林斯大陸大部分地區及城市的地圖，你注意到四周的牆上都
掛滿了精緻的地圖卷軸，每一幅地圖都有詳盡的地理環境介紹，真的是物
超所值。如果有需要你可以向老闆買。或著看看牆上的告示(note)。
LONG
	);
	set("item_desc", (["sign":@NOTE
[1;32m
佈告牌上寫著:

		buy       向老闆買東西
		list      老闆會告訴你這裡賣些什麼
		value     老闆會告訴你賣這件東西他會給你多少金幣
		sell      把某個東西賣給老闆
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room019",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}