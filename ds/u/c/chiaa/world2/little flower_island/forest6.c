//u/c/chiaa/world2/little flower_island/forest6.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", GRN"森林"NOR);
        set("long",@LONG
這裡是小花園的一座森林,四周林木纏繞,盡遮光線,
顯得陰暗至極讓人感到陣陣的陰森,森林裡傳出各種野獸的叫聲,
更令人毛骨悚然!讓你望之卻步!

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       "east"        : __DIR__"forest5",      //森林5
       "southwest"   : __DIR__"champaign4",   //平原4
   
  
  ]));
       
            setup();
replace_program(ROOM);
}
