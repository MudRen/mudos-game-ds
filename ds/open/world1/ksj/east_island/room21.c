#include <room.h>
inherit ROOM;

void create()
{
 set("short","草地");
 set("long",@LONG
這裡是農田旁的一片大草地，草地上長滿茂盛及膝的青草，是村
民用來放牧牲畜的地方，草地上有幾隻牛正在低頭吃草。
LONG);
   set("exits",([ 
       "east":__DIR__"room16",
       "west":__DIR__"room26",
       "north":__DIR__"room22",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/cow":2,
     ]) );
   setup();
}            
