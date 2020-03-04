#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
兩旁空無一物，洞穴頂端閃閃發亮，原來是垂掛的白水晶，將
這裡照的一閃一閃的，地上流著涓涓細水，洞口一道白光將這裡與
外界隔離，使得外面的河水不會倒灌，形成獨特的自然景觀。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room3",  
  "leave" : "/open/world1/tmr/area/m_river",

]));
        set("no_clean_up", 0);

        setup();
}

