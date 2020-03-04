#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit SSERVER;
void create()
{
        set_name(HIM"真"HIY"˙"HIR"死鎌刀"NOR,({"really-skickel","skickel"}) );
        set("long",
        "這是一把死神專用的鐮刀, 通體發出隱隱的血色。\n"
        "這把刀傳說是由西方死神在天外方界處，尋覓到的\n"
        "魔氣打造而成，據說打造此刀，花費了無數的人命\n"
        "和血氣，和七萬多龍年年的光陰，而成的狂霸王之\n"
        "之刀。( 聽說在1500年前死神之王被龍域域主- 遊\n"
        "龍俠擊敗之時, 也同時銷聲匿跡了。)           \n"
        );
        set_weight(1);
                if (clonep() )
        set_default_object(__FILE__);
                else {
                set("unit","把");
                set("value",1);
                set("volume",3);
                     }
           init_blade(100);
        setup();        
}
void init()
{
        add_action("do_die","die");
}

int do_die(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「死龍召喚」只能對戰鬥中的對手使用。\n");

        if( me->is_busy() )
                  return notify_fail("你的上一個動作還沒有完成，不能召喚他人。\n");
        if( me->query("mp") < 50 || me->query("ap") < 100 )
                return notify_fail("你的身體狀況不太好，無法施放這強烈的詛咒\n");
        if( me->query_temp("die"))
                return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision(HIR"\n$N一聲冷笑, 舉起手中武器, 對敵人快速一揮！！\n\n"NOR,me);
        me->set_temp("die",1);
        me->start_busy(1);
        call_out("do_killed",1, me, target);
        call_out("do_recall",2,me);
        return 1;
} 
int do_killed(object me,object target,int times)
{
  int i;
     if( random(100)>35 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("die");
      return notify_fail("目標慌慌張張的逃走了..\n");
      return 0;
    }
     message_vision(HIR"\n$N昂天快意的說: 吾愛, 我又幫你召喚到了一個奴隸了！！\n\n"NOR,me);
     
    {
         target->set_temp("temp/death_type",MAG"[死因: 死神召喚]"NOR);
          target->die();
          me->receive("ap",random(2));
          me->add("PKS",1);
          me->receive("mp",random(2));
    }
      return 0; 
   }
   else {
      message_vision(HIR"\n$N善心突起....在最後關頭止住了殺人意念\n\n"NOR,me);
          me->receive("hp",random(300));
   return 1;
   }
}
int do_recall(object me)
{
          if(!me) return 0;
          me->delete_temp("die");
          return 1;
}


