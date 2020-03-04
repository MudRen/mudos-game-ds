#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name("火槍",({"gun"}));
set_weight(5400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
這是一把西方巧手工匠所鑄造的射擊武器(shoot), 沒想到可以在東方的走私商看到這種東西.
LONG);
                set("unit", "把");
                set("rigidity",100);    //新增: 硬度
                set("material","iron");
                set("limit_int",10);
                set("limit_dex",10);
                set("limit_str",10);
        }


        set("bullet_type","small");     //可用子彈種類
        set("max_load",3);              //最大裝填量
        init_gun(13);   // 肉搏傷害力=set("weapon_prop/damage", 14);
        setup();
        set("value",6000);
}
int 
do_shoot(object me,object target)
{
  string msg;
        int damage;
        
          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
          msg=HIW+"$N"+HIW+"拿起"+this_object()->name()+HIW+"向$n"+HIW+"開了一";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="匹細如牛毛";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"﹗\n"+NOR;
                else msg+="迅彈﹗\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(2);
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
          //check if target can dodge
          if(COMBAT_D->attack_factor(me,this_object()->query("skill_type"))+COMBAT_D->dodge_factor(target,"dodge")+random(401) < 300 )
          {
           message_vision("$N一見情勢不妙, 閃身避開$n的射擊, 但臉色已微微一變。\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/6));
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
        
          damage=this_object()->query_temp("bullet/damage");
          damage= 80+damage*3;
          damage-=target->query_armor()/4-random(target->query_armor()/3);
       damage=damage + this_object()->query_skill("gun") / 3;
          if(damage<5) damage=random(10);
          if(damage<1)
          {
           message_vision(YEL+"$N"+YEL+"哈哈一笑, 把"+this_object()->query_temp("bullet/name")+YEL+"給撞開了。\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision(HIR"$N大吃一驚, 頓時身上多處槍傷, 看來受傷不輕"NOR"。\n",target,me);
          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) target->receive_wound("random",random(4)+1,me);
          target->add_busy(1);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}