#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","海政司-前庭");
set("long",@LONG
這裡就是海政司了, 你發現這裡堆積了很多一包一包的貨
物, 都是還未經海政司核準的貨物, 因此沒辦法交易, 不過如
此看來, 海政司的動作還真慢...
LONG
    );
 set("exits",([ "enter":__DIR__"seacoun9",
		"out":__DIR__"seacoun7",
]));
 set("objects", ([__DIR__"npc/seaguard" : 2,
		  __DIR__"npc/guard_leader": 1,
    ]));

 set("no_clean_up",0);
 set("light",1);
set("no_fight",1);
 setup();
}             

