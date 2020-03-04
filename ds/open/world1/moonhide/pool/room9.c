#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
這裡地形微微傾斜，所受到侵蝕的速度緩慢，然而形成了徐徐
的小山丘，軟性的土質，帶著四十五度角的斜度，往左方切了過去
，成為獨特的景觀。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room6",
  "south" : __DIR__"room10", 
  "north" : __DIR__"room8",
  "west" : __DIR__"room11",
])); 

        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/she-bun" : 2, 
]));
        set("no_clean_up", 0);

        setup();
}

