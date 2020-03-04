#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
地表下面，地下水消蝕節理與裂縫，雕塑出無數地洞，遍佈可
見，大部份河水常從這裡流失，且流失的速度很快。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room7",  
  "north" : __DIR__"room3",
])); 
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/la-ah" : 1,
]));
        set("no_clean_up", 0);

        setup();
}

