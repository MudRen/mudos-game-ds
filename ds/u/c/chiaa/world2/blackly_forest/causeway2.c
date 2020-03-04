//u/c/chiaa/world2/blackly_forest/causeway2.c

#include <ansi.h>    
inherit ROOM;

void create()
{
        set("short", "石子路");
        set("long", @LONG
你正在一條由碎石子鋪成的路上,崎嶇難行,很容易跌倒,
四周的光線相當昏暗,東方不遠處,有透出亮光!!
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
    "north"       : __DIR__"road7",      //林間小路7
    "south"       : __DIR__"trail2",     //幽徑2
    "northwest"   : __DIR__"road5",      //霧中小路5
    "southwest"   : __DIR__"trail1",     //幽徑1

]));
       
            setup();
replace_program(ROOM);
}

