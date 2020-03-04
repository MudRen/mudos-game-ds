// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"餐\廳"NOR);
	set("long", @LONG
這裡是一間餐廳，外部的裝潢很講究，也很別緻，有各種好吃好喝的
餐點，每個到這吃過的人都是贊不絕口的說好吃。而且這裡的服務態度也
不差喔。你看到一面牌子(note)。
LONG
	);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss2.c" : 1,
	]));

	set("item_desc", (["note":@NOTE
[1;32m
佈告牌上寫著:

		buy       向老闆買東西
		list      老闆會告訴你這裡賣些什麼
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room107",
	    "west" : __DIR__"room069",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","food");	// 餐廳

	setup();
	replace_program(ROOM);
}