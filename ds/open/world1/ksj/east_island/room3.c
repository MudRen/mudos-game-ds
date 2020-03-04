#include <room.h>
inherit ROOM;

void create()
{
 set("short","海岸");
 set("long",@LONG
這裡是小島的海岸邊，沙灘上平鋪著扁平的石板，形成一個曬鹽
場，鹽場中有淺淺的鹵水跟飄浮在鹵水上的半透明鹽種，鹽民們流著
如雨的汗滴將鹽晶用木扒聚集成堆。
LONG
    );
   set("exits",([ 
       "north":__DIR__"room2",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/salt-maker":3,
     ]));

   setup();
}            
