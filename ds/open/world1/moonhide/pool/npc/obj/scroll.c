#include <ansi.h>
inherit SSERVER;
inherit ITEM;
void create()
{
        set_name(HIG"妖精捲軸"NOR,({"elf scroll","scroll"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
               "妖精商所賣出的妖精捲軸，聽說有神奇的力量(elf_power)。\n");
             }
        set("value", 40000);
        set_weight(2000);     
  
        setup();
}
void init()
{
        add_action("do_elf_power","elf_power");
}

int do_elf_power(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「妖精捲軸」是用來打敵人的。\n");

        if( me->is_busy() )
                  return notify_fail("你的動作還未完成。\n");
        if( me->query("ap") < 50  )
                return notify_fail("你的氣勁不夠了，無法使用妖精捲軸。\n");
        if( me->query_temp("elf_power"))
                return notify_fail("你正在使用妖精捲軸。\n");
        message_vision(HIG"\n\t$N使出妖精捲軸裡的力量，一波又一波的殺氣，從捲軸裡竄出！\n"NOR,me);
        me->set_temp("elf_power",1);
        me->start_busy(5);
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
      me->delete_temp("elf_power");
      return notify_fail("好狗運 ! ! 被他逃了...\n");
      return 0;
    }
      message_vision(HIR"\n瞬間衝出十隻地精，以迅雷不及掩耳的速度，導引$N攻向"+target->query("name")+"\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),1);
          me->receive_damage("ap",random(10)+10);
    }
      return 0; 
   }
   else {
      message_vision(HIM"\n$N的力量似乎提不上來。\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}
int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("elf_power");
          return 1;
}

