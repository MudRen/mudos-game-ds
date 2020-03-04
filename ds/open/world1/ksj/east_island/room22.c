#include <room.h>
inherit ROOM;

void create()
{
 set("short","草地");
 set("long",@LONG
這裡是農田旁的一片大草地，草地上長滿茂盛及膝的青草，是村
民用來放牧牲畜的地方，草地上有幾隻小牛正在奔跑。
LONG);
   set("exits",([ 
       "west":__DIR__"room27",
       "south":__DIR__"room21",
       "north":__DIR__"room23",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/small-cow":3,
     ]) );
   setup();
}            
