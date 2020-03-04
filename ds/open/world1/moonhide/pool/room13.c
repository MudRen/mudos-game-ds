#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
這裡的土質，在乾燥地區最常見，為最肥沃的黑土與栗鈣土，
地表不時散出濃濃水氣，蒸散到洞頂，漸漸凝聚成水滴，順著洞頂
的形狀，環繞在兩旁，形成垂水的景觀。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room16",  
  "south" : __DIR__"room14", 
  "east" : __DIR__"room11",
  "north" : __DIR__"room12", 
])); 
     set("objects",([ /*sizeof == 1 */
__DIR__"npc/bu-la-fish":2,
]));        set("no_clean_up", 0);

        setup();
}

