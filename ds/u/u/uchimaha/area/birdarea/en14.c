#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","狐穴");

 set("long",@LONG
你繼續往深處走下去, 又看見了一群狐狸, 這裡的狐狸
似乎比之前的狐狸更為兇猛強壯, 它們一看見你, 就像發了
瘋似的撲上來, 張口便咬, 你為了活下去, 只好跟他們打了
起來了.....
LONG
    );
 
 set("exits",(["northeast":__DIR__"en15",
               "southwest":__DIR__"en13",
           ]));
 set("objects",([__DIR__"npc/fox4" : 3,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
