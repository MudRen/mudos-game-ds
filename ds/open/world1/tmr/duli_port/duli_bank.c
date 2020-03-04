// File: /d/duli_port/duli_bank.c
// Updated by tmr (Thu Feb 28 02:26:30 2002)

#include <room.h>
inherit BANK;

void create()
{
	  set("short", "杜尼港口銀行");
	  set("long", @LONG
這裡是一間頗具規模的商業銀行，清潔的十分乾淨的石磚地板，映著
過往顧客的倒影，天花板上的音響正播著一段清快的音樂，早已忙著不停
的櫃檯還是擠滿了兌錢、存款的人群。角落裡一個年邁的老婦人正用著拖
把一吋一吋的清理地板。
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"west" : __DIR__"map_10_16",
]));

        set("objects",([
                __DIR__"npc/bank_guard":2,
        ]));
	setup();
}
