// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"防具店"NOR);
	set("long", @LONG
防具是你在戰鬥中不可或缺的重要裝備之一，幸運的，你正站在全克
林斯大陸規模最大的防具店裡。有很多知名的防具在這裡販售，希望你會
喜歡。牆上掛著一個牌子(note)。
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
	    "west" : __DIR__"room062",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}