//u/c/chiaa/world2/blackly_forest/road6.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "霧中小路");
        set("long", @LONG
你正走在一條林中的小路,四週彌漫著一片淡霧,還透著一絲寒氣,
看到的景物盡是霧茫茫的看不甚清楚,往南迷霧深處瞧去,更慘白一片,
只怕走得進去,找不到路出來...
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "south"    : __DIR__"causeway1",     //石子路1
    
]));
           setup();
replace_program(ROOM);
}
