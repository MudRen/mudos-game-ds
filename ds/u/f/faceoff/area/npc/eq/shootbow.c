#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name("弩",({"shootbow"}));
set_weight(5400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
這是一把西方工匠所鑄造的射擊武器(shoot), 沒想到可以在東方的走私商看到這種東西.
LONG);
                set("unit", "把");
                set("rigidity",90);    //新增: 硬度
                set("material","wood");
	set("value",3000);
                set("limit_int",20);
                set("limit_dex",20);
                set("limit_str",20);
        }


        set("bullet_type","small");     //可用子彈種類
        set("max_load",1);              //最大裝填量
        init_gun(12);   // 肉搏傷害力=set("weapon_prop/damage", 14);
        setup();
        set("value",3000);
}
int 
do_shoot(object me,object target)
{
  string msg;
        int damage;
        
          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
          msg=HIW+"$N"+HIW+"拿起"+this_object()->name()+HIW+"向$n"+HIW+"射去一";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="隻迅捷無倫的";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"﹗\n"+NOR;
                else msg+="弩箭﹗\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(2);
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
          //check if target can dodge
          if(me->query_skill("gun")+me->query("dex")+random(20) < target->query_skill("dodge")+target->query("dex")+random(40))

          {
           message_vision("$N一見情勢不妙, 閃身避開$n的射擊, 但臉色已微微一變。\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/6));
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
        
          damage= this_object()->query_temp("bullet/damage");
          damage= 50+damage*3;
          damage-=target->query_armor()/3-random(target->query_armor()/4);
       damage=damage + this_player()->query_skill("gun") / 3;
          if(damage<5) damage=random(10);
          if(damage<5)
          {
           message_vision(YEL+"$N"+YEL+"哈哈一笑, 右臂疾伸, 竟將"+this_object()->query_temp("bullet/name")+YEL+"給抓下了。\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision(HIR"$N大吃一驚, 弩箭正中$N, 看來受傷不輕"NOR"。\n",target,me);
          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) target->receive_wound("random",random(1)+1,me);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}