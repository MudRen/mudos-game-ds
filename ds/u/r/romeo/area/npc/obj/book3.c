#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
       set_name(HIC"《王∼者∼之∼路》"NOR,({"king book","book"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "本");
          set("long",
"這是一張沾到菜油的白紙，上面隱隱約約浮出幾個字\n"
"符號，實不知有何用途。\n");
            }
        set("value", 0);
        set_weight(250);
                set("replica_ob",__DIR__"book1.c");
        setup();
}

void init()
{
        add_action("do_you","you");
}
int do_you(object target,string arg)
{
        object me;
        me=this_player();
      if( arg == "" ) return 0;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「秋末背歌」只能對戰鬥中的對手使用。\n");

        if (me->is_busy() )
                return notify_fail("你的上一個動作還沒有完成，不能施展特攻。\n";
      if(me->query("mp")<60 && me->query("ap")<100 ) return notify_fail("你的身;
        if(me->query_temp("you"))
                 return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision(HIR"\n$N氣凝神定，低聲說了幾句，突然大喝一聲，準備施展出;

         me->set_temp("you",1);
         me->start_busy(2);
        me->receive_damage("hp",20);
         me->receive_damage("ap",80);
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
      return notify_fail("目標似乎脫離了你的攻擊範圍..\n");
      return 0;
    }
      message_vision(HIR"\n$N仰天長嘯一聲，全身赤火乍現，對著"+target->query("n;
      for(i=0;i < times;i++)
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
      return 0;
   }
   else {
      message_vision(HIR"\n$N心煩意亂，一時間使不出「秋末悲歌」。\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)
{
         if(!me) return 0;
         me->delete_temp("you");
         return 1;
}

