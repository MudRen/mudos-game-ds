#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"路旁"NOR);
 set("long",@LONG
來到這裡，你發現這附近似乎是住宅區，旁邊都是一些民房
，但是很明顯的可以看到前面有一間十分老舊的房屋，不知為什
麼那間屋子會特別老舊•••••

LONG
    );

       set("exits",([
       "east":__DIR__"town33",
       "west":__DIR__"town11",
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

