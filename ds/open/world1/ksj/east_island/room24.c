#include <room.h>
inherit ROOM;

void create()
{
 set("short","農田");
 set("long",@LONG
種滿稻子的農田，田中有淺淺的水，深綠的稻子隨著微風吹過窸
窸作響，農人正在疏通田邊的水溝。
LONG);
   set("exits",([ 
       "west":__DIR__"room29",
       "south":__DIR__"room23",
       "north":__DIR__"room25",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/houjou":1,
     ]) );
   setup();
}            
