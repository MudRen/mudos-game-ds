#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIM"破爛的破布"NOR,({"bad boo","boo"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
               "好像是元素之王的寶貝 . . . 但 . . . 看不出來有什麼"
               "特別的，可能有其他用途吧(exert_power)。\n");
             }
        set("value", 100);
        set_weight(250);                set("replica_ob",__DIR__"boo2.c");
        setup();
}
void init()
{
        add_action("do_exert_power","exert_power");
}

int do_exert_power(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「究極力量」是用來打敵人的...\n");

        if( me->is_busy() )
                  return notify_fail("你的動作還未完成。\n");
        if( me->query("ap") < 10  )
                return notify_fail("你的氣勁不夠了，去補點回來再用吧。\n");
        if( me->query_temp("exert_power"))
                return notify_fail("你正在用究極力量了。\n");
        message_vision(HIC"\n$N空出一隻手，身成弓型，拳頭緊握並閃閃發光，忽然蹦地一聲 ! �                      向前一跨 ! ! 將四周空氣都震的吱吱作響 . . .                          「究」                          「極」 
                            「奧」
                              「義」\n",me);

        me->set_temp("exert_power",1);
        me->start_busy(2);
        call_out("do_crazy",3, me, target,10);
        call_out("do_clean",10,me);
        return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( random(100)>40 && me->query("ap")>10  )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("exert_power");
      return notify_fail("好狗運 ! ! 被他逃了...\n");
      return 0;
    }
      message_vision(HIY"\n「光」    「華」     「拳」   打向"+target->query("name")+"\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),1);
          me->receive_damage("ap",random(10)+10);
    }
      return 0; 
   }
   else {
      message_vision(HIM"\n$N的力量似乎提不上來。\n\n"NOR,me);
          me->receive_damage("ap",50);
   return 1;
   }
}
int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("exert_power");
          return 1;
}

