#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
       set_name("王者之路",({"book"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "本");
          set("long",
              "這是一張沾到菜油的白紙，上面隱隱約約浮出幾個字\n"
"你用力一看原來是「王∼者∼之∼路」四個字\n");
            }
        set("value", 0);
        set_weight(110);
                set("replica_ob",__DIR__"book3.c");
        setup();
}

void init()
{
        add_action("do_godie","godie");
}
int do_godie(object target,string arg)
{
        object me;
        me=this_player();
      if( arg == "" ) return 0;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「王者之路」只能在戰鬥中使用。\n");

        if (me->is_busy() )
return notify_fail("你的上一個動作還沒有完成，不能施展特攻。\n";
      if(me->query("mp")<60 && me->query("ap")<100 ) return notify_fail("你的身;
        if(me->query_temp("godie"))
                 return notify_fail("你的招式還沒施展，無法再使用了。\n");
message_vision(HIR"\n$N氣灌丹田，右手一抖，準備施展出;
         me->set_temp("godie",1);
         me->start_busy(2);
        me->receive_damage("hp",30);
         me->receive_damage("ap",90);
         call_out("do_crazy",4,me,target,6);
         call_out("do_clean",8,me);
         return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
if(me->query("mp")<30 && me->query("ap")<60 ) return notify_fail("你的身體狀況�;
     if( random(100)>30 && me->query("ap")>50 && me->query("mp")>30 )
  {
    if(!me) return 0;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("you");
      return notify_fail("對方已經夾著尾巴跑了。\n");
      return 0;
    }
      message_vision(HIR"\n$N一聲狂嘯，在$N的面前出現一口巨劍，對著"+target->query("n;
      for(i=0;i < times;i++)
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
      return 0;
   }
   else {
      message_vision(HIR"\n$N忽然一口鮮血湧出口中，一時間使不出「王者之路」。\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)
{
         if(!me) return 0;
         me->delete_temp("godie");
;
         return 1;
}

