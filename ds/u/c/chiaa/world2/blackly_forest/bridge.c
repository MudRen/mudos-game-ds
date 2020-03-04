//u/c/chiaa/world2/blackly_forest/bridge.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "橋");
        set("long", @LONG
你正走在森林的一座橋上,這座橋很久以前就有了,
已經相當的老舊,所以走起來搖搖晃晃,
深怕一個不小心便會摔了下去!!
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
     "east"  : __DIR__"fen_road2",           //綠沼小路2
     "west"  : __DIR__"road7",              //林間小路7
]));
       
        setup();
replace_program(ROOM);
}

