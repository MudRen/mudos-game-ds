// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"糖果屋"NOR);
	set("long", @LONG
這間糖果造型的商店，是間專門販賣零嘴、小點心的商店，店內一排
排整齊的食物架旁總是有客人在那挑選喜歡的零嘴。店員青春活潑的打扮
，著實讓人有種親切感。在牆上掛著一個牌子(sign)。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room090",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss4.c" : 1,
	]));

	set("item_desc", (["sign":@NOTE
[1;32m
佈告牌上寫著:
[1;33m
		buy       向老闆買東西
		list      老闆會告訴你這裡賣些什麼
[m
NOTE
        ]) );
	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","sell");	// 商店

	setup();
	replace_program(ROOM);
}