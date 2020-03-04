//u/c/chiaa/world2/blackly_forest/road2.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "林間小路");
        set("long", @LONG
你正走在林中的一條小路.耳中不時可聽到一些蟲鳴鳥叫,
別有一番清幽之意,林中樹木高聳群密,有種晦暗陰森的感覺!!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "south"  : __DIR__"road3",                //林間小路3
    "east"   : __DIR__"road4",                //林間小路4
    "west"   : __DIR__"forest_entranceway",   //森林入口處 
]));
       
            setup();
replace_program(ROOM);
}
