#include <room.h>
inherit ROOM;

void create()
{
 set("short","小攤子");
 set("long",@LONG
這裡擺了一個小攤子，攤子裡有個老婆婆正在捏著飯糰，攤子後
面是一間破舊的小木屋，從屋子煙囪冒出陣陣白煙。
LONG);
   set("exits",([ 
       "west":__DIR__"room13",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/old-woman":1,
     ]));
   setup();
}            
