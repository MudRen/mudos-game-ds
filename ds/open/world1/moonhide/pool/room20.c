#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
這裡不時出現好幾條的吻仔魚，它們似乎在開聚會一樣，圍成
一個小圈圈，每每個嘴裡，一直冒著氣泡，好像在討論什麼，魚的
世界真是有趣。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room17",
  "north" : __DIR__"room19",])); 
        set("objects",([ /* sizeoff() == 1 */
__DIR__"npc/bu-la-fish":4,
]));        set("no_clean_up", 0);

        setup();
}

