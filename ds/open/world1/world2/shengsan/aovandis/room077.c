// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"電腦賣場"NOR);
	set("long", @LONG
迎面而來的就是一張張貼在門口的海報，玻璃櫃上擺著一疊疊的電腦
報價單，玻璃櫃內陳列著各式的電腦商品。你看到幾個人為著一個小圓桌
，似乎正在討論價錢。這裡是市內有名的電腦賣場，在這裡你可以買到你
想要的高科技電腦產品。牆上還掛著一個告示牌(sign)。

LONG
	);
	set("item_desc", (["sign":@NOTE
[1;36m
佈告牌上寫著:
[1;32m
		buy       向老闆買東西
		list      老闆會告訴你這裡賣些什麼
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room062",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss5.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","sell");
	setup();
	replace_program(ROOM);
}