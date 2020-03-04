#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
河水流入廣闊的水域，水流驟然放緩，帶著大量沉積物聚集在
這裡，因此，受到岩屑的阻滯，把小流水分割成好幾個水道，每每
形成窄小的三角洲。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room16",
  "south" : __DIR__"room20",
  "west" : __DIR__"pool",
  "north" : __DIR__"room18",]));
        set("no_clean_up", 0);

        setup();
}

