#include <room.h>
inherit ROOM;

void create()
{
 set("short","農田");
 set("long",@LONG
種滿稻子的農田，田中有淺淺的水，深綠的稻子隨著微風吹過窸
窸作響，田中偶而可以看到泥鰍溜過。
LONG);
   set("exits",([ 
       "east":__DIR__"room25",
       "west":__DIR__"room35",
       "south":__DIR__"room29",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/loach":2,
     ]) );
   setup();
}            
