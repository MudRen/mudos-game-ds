#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit __DIR__"way00.c";

void create()
{
  set("short",HIG"山崖古道"NOR);
  set("long",(: print_mountain_msg :),);
  set("exits", ([ 
  "west" : __DIR__"way12",  
  "southeast" : __DIR__"way10",  
]));
        set("outdoors","land");

        setup();
}

void init()
{
  object me,ob; 
  me=this_player();      
  if(interactive(ob =this_player())) {
  }
   if (random(me->query_skill("dodge",1)) < 60)
     {
          message_vision(CYN"$N用不純熟的輕功\在棧道上行走，不經覺得又餓又累。\n"NOR,this_player());
          this_player()->add("ap",-5);
     }
     else
     {
           message_vision(CYN"$N以驚人的輕功\，快速有效率的通過棧道。\n"NOR,this_player());
     }
}
