//u/c/chiaa/world2/little flower_island/cave1.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", BLU"洞穴"NOR);
        set("long",@LONG
這裡的空氣感覺相當清涼,讓你感到一陣輕鬆,想休息一下,
你發現地上有一些炊飯的工具,似乎有人在這裡居住過,
不過在這孤島,怎麼會有人煙呢?你不禁的感到一陣疑惑,
四周圍好像有一股令人窒息的感覺。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
      
        "out"   : __DIR__"rock3",         //岩石區3
  
   ]));
       
            setup();
replace_program(ROOM);
}
