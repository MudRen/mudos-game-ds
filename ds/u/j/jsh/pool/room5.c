#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
連綿不斷的地下水，擴寬了既有的洞穴，並在這裡侵蝕出大大
小小，不同的地穴，有些還不時落下碎石，看似要崩塌一樣，經年
累月，在地上堆成了一座座小石堆。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room8",  
  "south" : __DIR__"room6",
  "east" : __DIR__"room2", 
])); 
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/la-ah" : 1, 
 __DIR__"npc/she-bun":1, 
]));
        set("no_clean_up", 0);

        setup();
}

