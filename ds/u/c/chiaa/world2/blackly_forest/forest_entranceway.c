//u/c/chiaa/world2/blackly_forest/forest_entranceway.c

#include <ansi.h>   

inherit ROOM;
void create()
{
        set("short", "森林入口處");
        set("long", @LONG
這裡是黑暗森林的入口處,光線彷彿照不進森林裡面,
使人有不舒服的感覺,也讓人產生是不是該回頭的想法!!
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east"       : __DIR__"road2",          //林間小路2
  "west"       : __DIR__"stream_road",    //溪邊小路

]));
       
            setup();
replace_program(ROOM);
}

