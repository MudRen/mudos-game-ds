// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"珠寶店"NOR);
	set("long", @LONG
你在一間珠寶店裡，櫃子裡有好多的貴重寶石及名貴裝飾品，城裡的
居民都會在這買到他們所喜愛的耳環、項鍊、戒指等等漂亮的飾品，種類
繁多，目不暇給。牆上有個佈告牌(note)。
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
	    "north": __DIR__"room012",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}