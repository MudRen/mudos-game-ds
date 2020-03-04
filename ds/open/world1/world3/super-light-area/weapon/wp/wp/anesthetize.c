#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(MAG"麻醉槍二代"NOR,({"anesthetize gun","gun"}));
set_weight(12700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
TEST武器.
LONG);
                set("unit", "把");
                set("rigidity",90);    //新增: 硬度
                set("material","iron");
                set("limit_int",15);
                set("limit_str",10);
        }

        set("bullet_type","small");     //可用子彈種類
        set("max_load",5);              //最大裝填量
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
          msg=HIW+"$N"+HIW+"舉起"+this_object()->name()+HIW+"向$n"+HIW+"射出一";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="發極為狠毒的";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"﹗\n"+NOR;
                else msg+="麻痺彈﹗\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(1);
me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
  if(me->query_skill("gun")+me->query("dex")+random(40) < target->query_skill("dodge")+target->query("dex")+random(20))
          {
           message_vision("$N一見情勢不妙, 閃身避開$n的射擊, 原力已頗為散漫!\n"+NOR,target,me);
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
           message_vision(YEL+"$N"+YEL+"哈哈一笑, 回身一轉"+this_object()->query_temp("bullet/name")+YEL+"。\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision(HIR"$N大吃一驚, 忽然噗的一聲, 子彈直入寸許\!"NOR"。\n",target,me);
          target->receive_damage("hp",damage,me);
          target->start_busy(10);
          if(random(10) == 1 ) target->receive_wound("random",random(2)+1,me);
          target->add_busy(10);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}

