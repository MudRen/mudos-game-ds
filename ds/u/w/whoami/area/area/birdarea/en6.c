#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");

 set("long",@LONG
你好不容易在峭壁上找到一處稍微凸出的岩石, 於是你決定
你現在來到東北澤林的深處, 四周一片陰暗, 空氣中有一股溼溼
的感覺, 令人十分的不舒服, 你望了望四周, 樹木多到數不清, 
你隱隱約約的看到這條路往東北方延伸下去。
LONG
    );
 
 set("exits",(["west":__DIR__"en5",
               "south":__DIR__"en4",
               "northeast":__DIR__"en7",
     ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup(); 
 replace_program(ROOM);
}           

