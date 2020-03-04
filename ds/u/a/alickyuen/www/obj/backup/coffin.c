#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("棺柩",({"coffin"}));
    set("unit", "個");
    set("long","不就是放死人的棺材嗎....");
    set_weight(999999);
    set("value", 1);
    set("no_sac", 1);
    set("no_get", 1);
    set("no_clean_up",1);
    setup();
}

void init()
{       
    add_action("do_push","push");
}

int do_push(string arg)
{
   object me,obj;
   me = this_player();
   obj = this_object();

   if(arg != "棺柩" && arg != "coffin")
      return notify_fail("你要推啥小？\n");

   if(environment(obj)->query("coffin_ok") == 1)
   {
      /*-----隨機動作未設-----*/
      message_vision(HIR"$N使勁的推開$n...\n"NOR,me,obj);
      call_out("open",3,me);
      return 1;
   }
   else
   { message_vision(HIR"$N使勁的想推開$n，幹...還是推不開阿！\n"NOR,me,obj); }
  return 1;     
}

int open(object me)
{
  switch( random(20) ) 
  {
      case 0..10:
           message_vision(HIG"棺柩內噴出一股氣體！\n"NOR,me);
//           me->apply_condition("poison", me->query_condition("poison")+random(10)+1);
           break;
      case 11..20:
           message_vision(HIY"棺柩內射出一隻箭，$N想閃避時卻已經被箭射中。\n"NOR,me);
//           me->receive_wound("random",random(4)+1,me);
//           me->apply_condition("blooding",me->query_condition("blooding")+random(5)+1);
           break;
//      default:
//
//           break;
  }
  message_vision("幹...可以拿BOX了唷？！\n",me);
  environment(me)->delete("coffin_ok");
  "/u/f/fedex/area/room5"->add("exits",(["westdown" : "/u/f/fedex/area/room6"]));
  return 1;
}
