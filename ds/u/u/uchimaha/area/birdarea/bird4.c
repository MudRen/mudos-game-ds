#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG
你又往上爬了一段距離, 發現你的身旁出現白霧, 
你又看了看, 不對! 是白雲! 原來你已經到達雲層中了,
你往上看了看, 還是看不到頂在那裡, 你不禁害怕起來,
但是你心想既然已經到這麼高了, 難到還要下去? 於是
你決定硬著頭皮繼續往上爬, 在你附近有個小洞。 

LONG
    );
 
 set("exits",(["up":__DIR__"bird5",
               "down":__DIR__"bird3",
               "enter":__DIR__"hole",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
