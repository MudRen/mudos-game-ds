#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
洞頂的水，從岩石縫裡湧出，在洞頂形成一自流泉，兩旁的石
頭佈達了小洞，不時還會冒出小螃蟹，在地上的水坑裡，還游著無
數的小蝌蚪。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room17",  
  "north" : __DIR__"room13",]));
        set("no_clean_up", 0);

        setup();
}

