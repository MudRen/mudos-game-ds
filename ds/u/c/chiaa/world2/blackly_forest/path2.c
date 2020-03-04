//u/c/chiaa/world2/blackly_forest/path2.c

#include <path.h>
inherit ROOM;
void create()
{
        set("short", "小徑");
        set("long", @LONG
這是一條頗不成路的小徑,其路的狹隘不過數步之寬,
行走其間,就像是在樹與樹之間的空隙行走,望西北方不遠處可看到一處空地,
如果走累了,不妨到那略事休息!!
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
     "west"       : __DIR__"road4",        //林間小路4
     "north"      : __DIR__"causeway1",    //石子路1
     "south"      : __DIR__"road7",        //林間小路7
     "northwest"  : __DIR__"vacancy1",     //林間空地1
]));
       
            setup();
replace_program(ROOM);
}
