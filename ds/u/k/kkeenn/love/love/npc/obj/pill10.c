#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(YEL"豹\胎易筋丸"NOR, ({ "pill" }));
        set("long",
"這是遼東神龍島的洪教主所煉之丹藥，有著增強功\力的奇妙效果，但是\n聽神龍教叛徒所訴，此藥的副作用也很可怕，一般教眾都敬而遠之•(swallow pill)"
        );
        set_weight(1500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        { 
                set("value",8000);
                set("unit", "粒");
        }
        setup();
}
void init()
{
add_action("do_eat", "swallow");
}
int do_eat(string arg)
{
        object me ,obj;
        me = this_player();
        obj = this_object();
        if( !arg )
        return notify_fail("你要吃啥 ﹖\n");
     if(obj->query("no_eat"))  return 0;
        if (arg != obj->query("id")) return notify_fail("你要吃啥 ﹖\n");
        me->add_temp("apply/str",5);
        me->add_temp("apply/con",5);
        me->add_temp("apply/int",5);
        me->add_temp("apply/dex",5);
       message_vision(HIR"$N一口氣將$n塞到嘴巴裡，$N爆吼一聲，全身經脈突起！\n"NOR,me,obj); 
        call_out("poison",180,me,obj);
     obj->set_temp("invis",1);
      obj->set("no_sell",1);
      obj->set("no_give",1);
      obj->set("no_drop",1);
      obj->set("no_get",1);
      obj->set("no_sac",1);
   obj->set("no_eat",1);
        return 1;
}
void poison(object me,object obj)
{
if(!me) return; 
message_vision(HIW"$N所服的"YEL"豹\胎易筋丸"HIW"的藥效慢慢退去了，$N的臉色突然變成青色的？\n"NOR,me);
 me->apply_condition("poison", me->query_condition("poison")+ (me->query_skill("combat")+random(me->query("con"))) );
 me->add_temp("apply/str",-5);   
 me->add_temp("apply/con",-5);   
  me->add_temp("apply/int",-5);   
  me->add_temp("apply/dex",-5);   
    destruct(obj);
return;
}

