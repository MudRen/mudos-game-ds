//u/c/chiaa/world2/little flower_island/brae3.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", CYN"山坡"NOR);
        set("long",@LONG
這裡是小花園的山坡,來到這裡與森林的感覺是完全不同的
有點陡的地形讓人行走更加不易,四周的景物不再是讓你覺得
陰暗恐怖,讓你不自覺的鬆了口氣,也降低了戒心!!

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
      
        "east"   : __DIR__"brae2",         //山坡2
        "west"   : __DIR__"champaign1",    //平原1
   ]));
       
            setup();
replace_program(ROOM);
}
