#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","市集");
set("long",@LONG
這裡位於市集的東南方, 不過交易與其它處同樣繁盛, 你發
現這裡所交易的東西大部份是土產, 也就是給外國商人採買的地
方, 你忽然發現你的東方有一家老舊的工坊, 似乎頗有名氣.....
LONG
    );
 set("exits",([ "north":__DIR__"seacoun23",
	    "west":__DIR__"seacoun27",
	    "east":__DIR__"seacoun40",
]));
 set("objects", ([__DIR__"npc/salesman3" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            