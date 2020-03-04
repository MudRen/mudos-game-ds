#include <room.h>
inherit ROOM;

void create()
{
 set("short","農田");
 set("long",@LONG
種滿稻子的農田，田中有淺淺的水，深綠的稻子隨著微風吹過窸
窸作響，田中有幾隻田蛙在稻叢中出沒。
LONG);
   set("exits",([ 
       "east":__DIR__"room20",
       "west":__DIR__"room30",
       "south":__DIR__"room24",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/frog":3,
     ]) );
   setup();
}            
