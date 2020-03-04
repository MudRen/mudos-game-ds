//u/c/chiaa/world2/little flower_island/champaign4.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HIG"平原"NOR);
        set("long",@LONG
這裡是一望無際的大草原,陣陣的風把草吹的有如
大海的波浪,一陣一陣向你襲來,煞是好看!!
你感覺清涼微風吹拂著你的身體,令人心曠神怡!!

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
       "east"        : __DIR__"champaign3",    //平原3
       "west"        : __DIR__"champaign5",    //平原5
       "enter"       : __DIR__"cave2",         //洞穴2
       "northeast"   : __DIR__"forest6",       //森林6
    ]));
       
            setup();
replace_program(ROOM);
}
