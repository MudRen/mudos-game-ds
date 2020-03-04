#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
不知道哪吹來的微風，使得沙粒落在丘脊上保持不動，愈堆愈
高，高出地表好幾餘尺，主要岩石的成份為雲母石，在丘脊部份，
凸出了一根石柱，與洞穴頂端相連接，應該就是此洞穴的支柱。 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room13",  
  "east" : __DIR__"room9",
])); 
        set("objects", ([ /*sizeof == 1*/
  __DIR__"npc/small-fish":1,
]));
        set("no_clean_up", 0);

        setup();
}

