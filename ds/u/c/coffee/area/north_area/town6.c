#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"街道"NOR);
 set("long",@LONG 
這裡突然很多人蜂擁而來，原來是在搶著取井裡的水，因
為這裡是偏於較寒冷乾燥的地區，取水相當不容易，村裡的村
民都靠全村唯一的井生活，不然要取水就要十分麻煩。
LONG
    );

 set("exits",(["north":__DIR__"town7",
               "south":__DIR__"town5",
               "west":__DIR__"town12",
               "east":__DIR__"town13",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}        


