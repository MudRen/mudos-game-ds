#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
        set_name(HIB"雷鳴十字弓"NOR,({"thunder crossbow","crossbow"}));
        set("long","一把平凡無奇的弓，唯一特殊之處只有那前端的進氣響孔，一但弓箭射出\n" 
                   "就會發出類似雷擊的聲響，讓敵人不知所措•\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(5700);
                set("unit", "把");
                set("value",4000); 
                set("volume",5);
        }

        set("rigidity",110);    //新增: 硬度
        set("material","iron");
        set("limit_int",45);
        set("limit_dex",45);
        set("limit_str",65); 
        set("limit_lv",35);
        set("bullet_type","small");     //可用子彈種類
        set("max_load",20);              //最大裝填量
        init_gun(15);   // 肉搏傷害力=set("weapon_prop/damage", 14);
        setup();
}

int do_shoot(object me,object target)
{
        string msg;
        int damage,time,times,delay;
        times = random(me->query_skill("gun")/40 + me->query("dex")/30)+1;
        if(times>3) times=3;

          if(!me || !target) return 0;
          this_object()->set_temp("loaded",this_object()->query_temp("loaded")-times);
          msg=HIW+"$N"+HIW+"拿起"+this_object()->name()+HIW+"向$n"+HIW+"射出"+chinese_number(times);
          if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
                else msg+="隻極為快速的";
          if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"﹗\n"+NOR;
                else msg+="迅箭﹗\n"+NOR; 
           tell_object(target,"你被耳邊的雷鳴聲給震懾住，一時不能動彈…\n");
           delay = random(me->query("Merits/bio"))+1;
           if(delay>3) delay=3;           target->start_busy(delay); 

          if(!me->is_fighting(target)) me->kill_ob(target);
          message_vision(msg,me,target);
          me->start_busy(1+random(3));

       for (time=0;time<times;time++)
         {     
          me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
          //check if target can dodge
          damage=this_object()->query_temp("bullet/damage");
          damage=60+damage*3;
          damage-=target->query_armor()/3-random(target->query_armor()/3);
          damage=damage + this_player()->query_skill("gun") / 3 * 2 ;
          if(damage<5) damage=random(10);
          if(damage<1)
          {
           message_vision(YEL+"$N"+YEL+"游刃有餘, 閃身避過"+this_object()->query_temp("bullet/name")+YEL+"。\n"+NOR,target);
           if(!target->is_fighting(me)) target->kill_ob(me); 
           return 0;

          }
          if(me->query_skill("gun")*2+me->query("dex")+random(40)+me->query("Merits/tec")*10 
          < target->query_skill("dodge")+target->query("dex")+random(40)+target->query("int") )
          {
           message_vision("$N一見情勢不妙, 閃身避開$n的射擊, 架式已頗為狼狽!\n"+NOR,target,me);
           target->improve_skill("dodge",1+random(target->query_int()/6));
           if(!target->is_fighting(me)) target->kill_ob(me);
          } else {
          message_vision(HIR"$N大吃一驚, 忽然噗的一聲, 箭身直入寸許\!!"NOR,target,me); 
          if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
          tell_object(target,HIR"("+damage+")\n"NOR);
          if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
          tell_object(me,HIR"("+damage+")\n"NOR);

          target->receive_damage("hp",damage,me);
          if(random(10) == 1 ) {
          target->receive_wound("random",random(2)+1,me);
          target->add_busy(random(1));
          }
          COMBAT_D->report_status(target);
          if(!target->is_fighting(me)) target->kill_ob(me); 
          }
         }
         return 1;
}

