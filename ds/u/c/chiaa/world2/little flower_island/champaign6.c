//u/c/chiaa/world2/little flower_island/champaign6.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HIG"平原"NOR);
        set("long",@LONG
這裡是一望無際的大草原,陣陣的風把草吹的有如
大海的波浪,一陣一陣向你襲來,煞是好看!!
你感覺清涼微風吹拂著你的身體,令人心曠神怡!!
南方不遠處好像有個洞穴!!


LONG
        );
        set("exits", ([ /* sizeof() == 3 */
       "west"        : __DIR__"rock4",         //岩石區4
       "north"       : __DIR__"champaign2",    //平原2
       "south"       : __DIR__"rock5",         //岩石區5
    ]));
       
            setup();
replace_program(ROOM);
}
