// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"藍藍銀行"NOR);
	set("long", @LONG
這間銀行相當的有規模，潔淨的環境很讓人神清氣爽。銀行員認真的
在為客戶服務，為的是讓銀行能越做越大，客戶越來越多。有一塊板子(board)
上面有公告的東西，也許你該看一看。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room088",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/miss3.c" : 1,
	]));

	set("item_desc", (["board":@NOTE
[1;32m
佈告牌上寫著:

	deposit		開戶：存錢
	withdraw	領錢

[m
NOTE
        ]) );

	set("no_clean_up", 0);
	set("valid_startroom",1);
	set("light", 1);
	set("room_type","bank");	// 銀行錢莊

	setup();
	replace_program(ROOM);
}