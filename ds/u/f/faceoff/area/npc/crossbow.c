#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(CYN"十字弓"NOR,({"crossbow"}));
set_weight(5700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
這是一把西方巧手工匠所鑄造的射擊武器(shoot), 比弩又多了幾分殺傷力.
LONG);
                set("unit", "把");
                set("rigidity",110);    //新增: 硬度
                set("material","iron");
                set("limit_int",9);
                set("limit_dex",10);
                set("limit_str",9);
        }


        set("bullet_type","small");     //可用子彈種類
        set("max_load",3);              //最大裝填量
        init_gun(16);   // 肉搏傷害力=set("weapon_prop/damage", 14);
        setup();
        set("value",5000);
}
int 
do_shoot(object me,object target)
{
  string msg;
        int damage;
        
          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
          msg=HIW+"$N"+HIW+"拿起"+this_object()->name()+HIW+"向$n"+HIW+"射出一";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="隻極為快速的";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"﹗\n"+NOR;
                else msg+="迅箭﹗\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(1);
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
          //check if target can dodge
          if(me->query_skill("gun")+me->query("dex")+random(40) < target->query_skill("dodge")+target->query("dex")+random(40))
          {
           message_vision("$N一見情勢不妙, 閃身避開$n的射擊, 架式已頗為狼狽!\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/6));
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
        
          damage=this_object()->query_temp("bullet/damage");
          damage= 100+damage*3;
          damage-=target->query_armor()/3-random(target->query_armor()/3);
       damage=damage + this_player()->query_skill("gun") / 3 * 2 ;
          if(damage<5) damage=random(10);
          if(damage<1)
          {
           message_vision(YEL+"$N"+YEL+"哈哈一笑, 閃身避過"+this_object()->query_temp("bullet/name")+YEL+"。\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision(HIR"$N大吃一驚, 忽然噗的一聲, 箭身直入寸許!"NOR"。\n",target,me);
          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) target->receive_wound("random",random(2)+1,me);
          target->add_busy(1);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}