//u/c/chiaa/world2/little flower_island/rock5.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HBK"岩石區"NOR);
        set("long",@LONG
這裡是小花園的岩石區,到處都是由巨大的岩石所組成,經過
長時間的風吹日曬,每塊岩石都有著特殊的形狀,構成一種奇異
的景觀,在每塊岩石之間好像有生物活動著!!

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       "north"    : __DIR__"champaign6",    //平原6
       "enter"     : __DIR__"cave3",        //洞穴3
    ]));
       
            setup();
replace_program(ROOM);
}
