//u/c/chiaa/world2/blackly_forest/road5.c

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
        set("exits", ([ /* sizeof() == 2 */
    "west"         : __DIR__"road3",         //林間小路3
    "north"        : __DIR__"road4",         //林間小路4
    "southeast"    : __DIR__"causeway2",     //石子路2
]));
       
            setup();
replace_program(ROOM);
}


