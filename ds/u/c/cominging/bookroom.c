#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", " == JohnnyS 書房 == ");
	set("long", @LONG

這裡就是一間書房, 擺設平凡, 沒什麼特別, 桌上有幾張紙條, 也許
可以(w_note)來提醒自己事項, 旁邊有個報紙架∼∼

LONG
	);
//        set("exits", ([  "west" : __DIR__"walkway.c"  ]));
	set("objects", ([
  __DIR__"item/paper_shelf.c": 1
]));
	set("outdoors", "forest");
	set("light", 1);
	set("no_clean_up", 0);
	setup();
        call_other("/obj/board/lpc_b.c", "???");
}
