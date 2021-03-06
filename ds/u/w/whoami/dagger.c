#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit DAGGER;

void create()
{
        set_name(MAG"十方靈動"NOR,({"viper dagger","dagger"}) );
        set("long","一把紫色的匕首，形狀像是一條蛇，當你注意看時，好像會如有生命般
緩緩遊動，匕上有隱隱約約的看到一層紫氣。\n");
        set_weight(2300);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
              set("value",20000);
              set("limit_level",35); 
              set("limit_str",15);
              set("limit_dex",65);
              set("material", "blacksteel");
        }
        set("wield_msg","$N握住了$n，手上紫氣隱隱顯現。\n");
        init_dagger(30+random(10));
        set("replica_ob", __DIR__"dagger.c");
        set("weapon_prop/bar", 1);
        set("weapon_prop/str", 3);
        set("weapon_prop/bio", 1);
        set("weapon_prop/dex", 3);
        set("weapon_prop/int", -4);
        setup();        
}


 
void attack(object me,object victim)
{ 
  int attack_times,aa,mysk,myint,hp,max_hp,power,durable;
  object ob = this_object();      
  object newob;
        hp = me->query("hp"); 
        max_hp = me->query("max_hp");
        ::attack(); 
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;

     switch ( random(5) ) {
      case 0..3:                   
        if(random(5)) return; // 1/5 的機率特攻
        message_vision("\n$N手中的"MAG"十方靈動"NOR"的攻勢如蛇一般向前突進數招！\n\n"NOR,me,victim);
        attack_times=me->query("MKS")/10000;

        if (attack_times < 1) attack_times = 1;        
        if (attack_times > 3) attack_times = 3;        

        myint = me->query("int");
        mysk = me->query_skill("dagger");
        power= (mysk+myint)/2;

        for (aa=0;aa<attack_times;aa++)
        { 
         me->add_temp("apply/damage",power);
         COMBAT_D->do_attack(me, victim, this_object(), random(4));
         COMBAT_D->report_statue(victim); 
         me->add_temp("apply/damage", -power);  
        }
      break;
      default: 
        if( random(hp) < (max_hp/2) ) {
           message_vision("\n$N手中的$n突然幻化成一條"MAG"紫色的巨蟒"NOR"，加入了這場戰鬥！\n\n"NOR,me,ob);

           durable = ob->query_temp("durable");
           newob = new(__DIR__"snake"); 
           newob->set_temp("durable",durable);

           newob->set("level",me->query("level")*2/3); 
           newob->set("str",me->query("str")*3/2);
           newob->set("con",random(me->query("con")*3/2)); 
           newob->set("int",me->query("int")*3/2);
           newob->set("dex",random(me->query("dex")*3/2));
           newob->set("Merits/bar",(newob->query("con")+newob->query("str"))/30+random(2));
           newob->set("Merits/wit",newob->query("dex")/40+newob->query("int")/25+random(2));
           newob->set("addition_armor",random(me->query("level"))*2); 
           newob->set("addition_damage",random(me->query("level"))*2); 
           newob->set("apply/hit",random(me->query_skill("dagger")/3));  
           newob->set("apply/dodge",random(me->query_skill("dodge")/3));
 
           newob->set("max_hp",newob->query_con()*33);
           newob->set("max_mp",(newob->query_int()*25+newob->query_con()*5));
           newob->set("max_ap",(newob->query_int()*5+newob->query_con()*25));
           newob->set("hp",newob->query("max_hp"));
           newob->set("ap",newob->query("max_ap"));
           newob->set("mp",newob->query("max_mp"));
           newob->move(environment(me)); 
           newob->kill_ob(victim);
           victim->kill_ob(newob);
           destruct(ob);
           }
      break;      
      }
return;
} 

