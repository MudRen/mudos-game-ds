#include <ansi.h>#
inherit ROOM;

void create()
{
        
        set ("short",HIR"天羅迷陣"NOR);
        set ("long", @LONG
這裡是天界所設下的絕陣，此陣是為了不讓心懷邪念的人進出，
想過此陣，只要心裡無半點邪念和滿懷孝心的人，努力的走一定能通
過此陣的。
LONG

);
        set("hide_exits", ([ /* sizeof() == 6 */
                  "east" : __DIR__"room2",
                  "west" : __DIR__"room3",
                  "north" : __DIR__"room8",
                  "northwest" : __DIR__"room4", 
                  "south" : __DIR__"room5",
"southeast" : __DIR__"room6",
"northeastup" : __DIR__"room",                                   
     ]));
        set("light",0);
        set("no_map",1);
        set("no_clean_up", 0);
setup();
}

