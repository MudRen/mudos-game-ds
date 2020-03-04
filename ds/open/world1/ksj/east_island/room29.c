#include <room.h>
inherit ROOM;

void create()
{
 set("short","農田");
 set("long",@LONG
種滿稻子的農田，田中有淺淺的水，深綠的稻子隨著微風吹過窸
窸作響，幾個農夫正彎著腰辛勤地在田中除草。
LONG);
   set("exits",([ 
       "east":__DIR__"room24",
       "south":__DIR__"room28",
       "north":__DIR__"room30",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/farmer":2,
     ]) );
   setup();
}            
