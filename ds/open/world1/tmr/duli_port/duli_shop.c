// File: /d/duli_port/duli_shop.c
// Updated by tmr (Wed Feb 27 21:34:15 2002)

#include <room.h>
inherit HOCKSHOP;

void create()
{
	  set("short", "杜尼小商店");
	  set("long", @LONG
這裡是一間買賣東西的商店，店內牆壁上掛了大大一張的營業証書，
七、八個西裝筆挺員工正在各個櫃檯上進行和顧客的交易及處理事項，門
口不斷的進來想要交易的顧客，大概是因為這間商店位於港口的附近，生
意客源才會如此興盛不斷。
LONG
	  );
	  set("objects", ([ ]));
	  set("exits", ([ /* 1 element(s) */
	"south" : __DIR__"map_5_9",
]));

	setup();
}
