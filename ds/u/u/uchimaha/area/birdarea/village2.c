#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");
 set("long",@LONG
你沿著泥土路走到了裡, 樹林分布在路兩旁, 附近
有一些奇怪的花草, 在你的東方有著一個巨大無比的石
拱門和一些人, 這條路往東邊延伸下去.
LONG
    );
 
 set("exits",(["west":__DIR__"village1",
               "east":__DIR__"village3",
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
