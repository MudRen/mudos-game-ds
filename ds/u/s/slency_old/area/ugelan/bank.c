// Room: /u/s/slency/area/ugelan/bank.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIW"幽遮蘭銀行"NOR);
	set("long", @LONG
這裡是本地最大的一家銀行，提供查詢帳目與提錢存款的業務，你
可以看見許多人在這裡處理一些身上的財務，身為旅行者的你，身上帶
太多的現金絕不是明智之舉，有了此種服務，你可以到處提領你需要旅
費, 既方便又可降低風險，有關此地銀行所提供的服務請查詢工作人員
。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road8",
]));
	set("objects", ([ /* sizeof() == 2 */
 __DIR__"npc/banker" : 1,
 __DIR__"npc/roken" : 1,
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
