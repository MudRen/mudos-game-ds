//u/c/chiaa/world2/blackly_forest/nivi_road1.c

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
    "south"  : __DIR__"nivi_road2",     //忍村道路2
    "north"  : __DIR__"garrison2",      //駐守處2
    "east"   : __DIR__"parade1",        //練習區1
]));
       
            setup();
replace_program(ROOM);
}
