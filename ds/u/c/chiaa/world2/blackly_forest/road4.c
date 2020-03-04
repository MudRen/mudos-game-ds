//u/c/chiaa/world2/blackly_forest/road4.c

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
    "east"        : __DIR__"path2",       //小徑2
    "west"        : __DIR__"road2",       //林間小路2
    "south"       : __DIR__"road5",       //霧中小路5
   ]));
       
            setup();
replace_program(ROOM);
}
