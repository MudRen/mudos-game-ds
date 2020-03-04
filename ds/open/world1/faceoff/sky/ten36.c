#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"懸空鋼橋"NOR);
 set("long",@LONG
這裡鋼索分出了許多分支, 看來真是複雜透頂, 不知道
應該走哪一條 ??
LONG
    );
 set("exits",([  "north":__DIR__"ten35",
                 "south":__DIR__"ten36",
                 "east":__DIR__"ten34",
                 "west":__DIR__"ten37",
    ]));
set("no_map",1);
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
  object me;
  me =this_player();
  if( interactive(me = this_player()) && !me->is_fighting())
  {
  remove_call_out("hi");
  call_out("hi",1,me);
  }
}
void hi(object me)
{
        tell_object(me,CYN"你漸漸的失去了平衡感....\n"NOR);
        call_out("cold",5,me);
        return;
}
void cold(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,CYN"你感到你的內力已經漸漸支持不住這裡的酷寒了...\n"NOR);
     me->receive_damage("ap",30);
     call_out("cold2",7,me);
     return;
}
void cold2(object me)
{
if(!me || environment(me) != this_object()) return;
     tell_object(me,CYN"你感到情形越來越不妙了, 你的身形漸漸開始搖晃, 輕功\慢慢渙散開來了....\n"NOR);
     me->receive_damage("hp",250);
     call_out("cold3",8,me);
     return;
}
void cold3(object me)
{
if(!me || environment(me) != this_object()) return;
    tell_object(me,CYN"你慢慢的向左傾斜, 終於無法克制的向下墬去 !!\n"NOR);
     me->receive_damage("hp",230);
    me->move(__DIR__ "ten29");   
     return;
}


