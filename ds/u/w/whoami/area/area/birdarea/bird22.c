#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"天梟教"NOR"練武場");

 set("long",@LONG
你來到天梟教的練武場, 你看看四周, 發現這裡除了一些石
樁以外別無他物, 你走過去看了看石樁, 發現原來這裡是專門練
習靈翼八步訣的石樁, 你敲了敲石樁, 原本這裡的石樁硬度都不
一樣, 假如一個不小心可能會把這石樁給踩斷, 所以練起來加倍
的困難。
LONG
    );
 
 set("exits",(["south":__DIR__"bird14",
               "north":__DIR__"bird20",
               
     ]));
 set("outdoors","land"); set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

