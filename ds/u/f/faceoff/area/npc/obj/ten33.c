#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"懸空鋼橋"NOR);
 set("long",@LONG
你爬上了鋼索之上, 卻發現上面宛如蜘蛛網班錯綜迷離, 
而且你的足下始終都只有一條粗如手腕的鋼索, 一個不小心
就會摔下萬丈深淵,而或許是因為這裡地勢較高,因此這裡相
當的寒冷....
LONG
    );
 set("exits",([  "north":__DIR__"ten34",
    ]));
set("no_map",1);
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
  object me,where;
  where = load_object(__DIR__"ten29");
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
    me->move(where);
     return;
}
