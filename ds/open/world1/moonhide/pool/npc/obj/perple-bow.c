#include <weapon.h>
#include <ansi.h>
inherit GUN; 
inherit F_UNIQUE;
void create()
{
set_name(HIW"紫煌定風弓"NOR,({"purple-bow","bow"}));
set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
繼紫煌定風劍後，竭達羅又打造一把舉世無雙的弓，乃是取自十萬
大山的靈鳥骨所製。 
LONG);
                set("unit", "把");
                set("rigidity",200);    
                set("material","gold");
                set("limit_int",30);
                set("limit_dex",40);
                set("limit_str",35); 
                set("replica_ob",__DIR__"perple-bow2");
        }
        set("bullet_type","small");     
        set("max_load",10);              
        init_gun(70);   
        setup();
        set("value",20000); 
}
int 
do_shoot(object me,object target)
{
  string msg;
        int damage;
        
          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
          msg=HIW+"$N"+HIG+"舉起"+this_object()->name()+HIR+"向$n"+HIR+"射出一";
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="枝音速的";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"﹗\n"+NOR;
                else msg+="音速箭﹗\n"+NOR;
           if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(1);
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
            if(me->query_skill("gun")+me->query("dex")+random(50) < target->query_skill("dodge")+target->query("dex")+random(80))
          {
           message_vision("$N以美妙的步法, 輕鬆閃開$n的射擊 ~ ~\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/8));
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
        
          damage=this_object()->query_temp("bullet/damage");
          damage= 100+damage*4;
          damage-=target->query_armor()/4-random(target->query_armor()/4);
       damage=damage + this_player()->query_skill("gun") / 4 * 2 ;
          if(damage<5) damage=random(20);
          if(damage<1)
          {
           message_vision(HIC+"$N"+HIW+"左右的亂跳,閃過了"+this_object()->query_temp("bullet/name")+HIG+"。\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           return 1;
          }
          message_vision(HIR"$N面有難色, 雙手緊握住插入腹中之箭!"NOR"。\n",target,me);
          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) target->receive_wound("random",random(2)+1,me);
          target->add_busy(1);
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me);
          return 1;
}


