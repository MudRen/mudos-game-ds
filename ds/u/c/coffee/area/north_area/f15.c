#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內"NOR);
 set("long",@LONG 
在這裡，野獸的吼叫聲傳遍四周，你感覺好像已經被野獸包
圍起來了。四周雖然黑暗，但好像有數對紅色的眼睛這在惡狠狠
的瞪視著你，那你不禁開始毛毛的。
LONG
    );

       set("exits",([        
       "east":__DIR__"f16",           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

