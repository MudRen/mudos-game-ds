#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"街道"NOR);
 set("long",@LONG 
走到這裡，旁邊幾乎都是當地居民的住宅。前方也有一些市
集、商店等，十分熱鬧。但是這裡的地板卻全都是黃土、還有一
些小石子。加上這裡天氣十分乾燥，讓你開始覺得口渴了。
LONG
    );

 set("exits",(["north":__DIR__"town5",
               "south":__DIR__"town3",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}        
