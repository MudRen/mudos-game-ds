#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"街道"NOR);
 set("long",@LONG 
在這裡可以聽到遠方傳來的叫賣聲，應該是這附近的商店或
攤販吧。不過，這裡的空氣實在太乾燥了，讓你忍不住開始覺得
口渴，只見前面有一口大井，你也許可以過去看看有沒有水喝！
LONG
    );

 set("exits",(["north":__DIR__"town6",
               "south":__DIR__"town4",
               "west":__DIR__"town10",
               "east":__DIR__"town11",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}        

