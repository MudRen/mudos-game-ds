//u/c/chiaa/world2/blackly_forest/nivi_road2.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG
你正走在忍者村的一條道路,路上的行人對你這個 
意外的訪客,似乎有存著很高的警戒心和好奇心!!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "south"  : __DIR__"nivi_square1",       //廣場1
    "north"  : __DIR__"nivi_road1",         //忍村道路1
    "west"   : __DIR__"nivi_road3",         //忍村道路3
]));
       
            setup();
replace_program(ROOM);
}


