#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內"NOR);
 set("long",@LONG 
來到這裡，只雖然十分黑暗，但你似乎感覺到前面好像有一
股邪氣，擋住你的去路，如果要經過這裡，似乎要和他一絕死戰
！否則只好往回走了。
LONG
    );

       set("exits",([        
       "north":__DIR__"s2", 
       "down":__DIR__"s1",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}
