#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FORK;
void create()
{
     set_name( HIW"九"HIY"尾"NOR"之牙"HIR"《槍》"NOR,({"nine tail tooth","tooth","pike"}) );
     set_weight(12000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","九尾的牙齒，隱隱發出些許\的妖力，似乎可以轉變成別種武器•\n"
                  +"( change <type>, ex: change sword )\n"
                  +"( type : pike sword blade dagger staff)\n");
            set("unit", "件");             
            set("value",11000);
            set("material","gold"); 
            set("replica_ob",__DIR__"tooth1");
           }         
        set("limit_str",20);
        set("limit_level",40);
        set("weapon_prop/str",3);
        set("weapon_prop/con",1);
        set("weapon_prop/int",-2);
        set("weapon_prop/dex",-1);
        set("weapon_prop/bar",1);
        set("weapon_prop/tec",-1);
        set("weapon_prop/hit",15);
        init_fork(73);
        setup();
}
void init()
{
    add_action("do_change","change");
}
int do_change(string str)
{ 
   object ob = this_object();   if( ob->query("equipped") )
   return notify_fail("請先解除裝備。\n"); 
   switch(str)
   {
     case "staff":
           set("skill_type", "staff");
set_name(HIW"九"HIY"尾"NOR"之牙"HIY"《杖》"NOR,({"nine tail tooth","tooth","staff"}));
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化………\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIY"杖形"NOR"了•\n");
           set("weapon_prop/str",1);
           set("weapon_prop/con",3);
           set("weapon_prop/int",3);
           set("weapon_prop/dex",-3);
           
           set("weapon_prop/bar",0);
           set("weapon_prop/tec",-1);
           set("weapon_prop/sou",-1);
           set("weapon_prop/bio",1);
           set("weapon_prop/wit",1);
           
           set("weapon_prop/hit",15);
           break;
     case "sword":
           set("skill_type", "sword");
set_name(HIW"九"HIY"尾"NOR"之牙"HIG"《劍》"NOR,({"nine tail tooth","tooth","sword"}));  
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化………\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIG"劍形"NOR"了•\n");
           set("weapon_prop/str",-2);
           set("weapon_prop/con",2);
           set("weapon_prop/int",-1);
           set("weapon_prop/dex",1);
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",0);
           set("weapon_prop/sou",0);
           set("weapon_prop/bio",1);
           set("weapon_prop/wit",-2);
           
           set("weapon_prop/hit",0);
           break;
     case "blade":
           set("skill_type", "blade");
set_name(HIW"九"HIY"尾"NOR"之牙"HIC"《刀》"NOR,({"nine tail tooth","tooth","blade"}));  
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化………\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIC"刀形"NOR"了•\n");
           set("weapon_prop/str",2);
           set("weapon_prop/con",4);
           set("weapon_prop/int",-1);
           set("weapon_prop/dex",-2);
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",0);
           set("weapon_prop/sou",-1);
           set("weapon_prop/bio",0);
           set("weapon_prop/wit",0);

           set("weapon_prop/hit",10); 
           break;
     case "dagger":
           set("skill_type", "dagger");
set_name(HIW"九"HIY"尾"NOR"之牙"HIW"《匕》"NOR,({"nine tail tooth","tooth","dagger"}));  
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化………\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIW"匕形"NOR"了•\n");
           set("weapon_prop/str",3);
           set("weapon_prop/con",-2);
           set("weapon_prop/int",-2);
           set("weapon_prop/dex",3);
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-2);
           set("weapon_prop/sou",0);
           set("weapon_prop/bio",1);
           set("weapon_prop/wit",0);
           
           set("weapon_prop/hit",11); 
           break;
     case "pike":
           set("skill_type", "fork");
set_name(HIW"九"HIY"尾"NOR"之牙"HIR"《槍》"NOR,({"nine tail tooth","tooth","pike"}));  
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化………\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIR"槍形"NOR"了•\n");
           set("weapon_prop/str",3);
           set("weapon_prop/con",1);
           set("weapon_prop/int",-2);
           set("weapon_prop/dex",-1);
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-1);
           set("weapon_prop/sou",0);
           set("weapon_prop/bio",0);
           set("weapon_prop/wit",0);
           
           set("weapon_prop/hit",15);
           break;
     default:      
           write("九尾之牙沒有這種形態！\n");
   }
     return 1;
}

void attack(object me,object victim)
{
  object ob = this_object();      
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(4)) return; // 1/4 的機率特攻
        message_vision("$N"HIY"手中的$n"HIY"散出大量的"NOR+MAG"妖氣"HIY"………\n"NOR,me,ob);
        COMBAT_D->do_attack(me, victim, this_object(), random(5));
        COMBAT_D->report_statue(victim);  
        victim->add_busy(1); 
        me->add_busy(2);
        if( me->query("ap") > 300 ){
           switch( random(9) ){
           case 0..3: 
            message_vision("\n$N"HIR"手上的$n"HIR"像有了生命般的動了起來！！\n\n"NOR,me,ob);
            COMBAT_D->do_attack(me, victim, this_object(), random(5));
            COMBAT_D->report_statue(victim); 
            COMBAT_D->do_attack(me, victim, this_object(), 4);
            COMBAT_D->report_statue(victim); 
            COMBAT_D->do_attack(me, victim, this_object(), random(5));
            COMBAT_D->report_statue(victim);
            victim->add_busy(1);
           break; 
           default:
            message_vision(HIB"\n突然$n"HIB"妖氣大盛，$N無法控制手中的$n"HIB"，招式不自覺的一滯………\n"NOR,me,ob);
            me->receive_damage("hp",random(200));
            me->start_busy(2);
           break;
           }
        } else {
         message_vision(HIB"\n突然$n"HIB"妖氣大盛，$N無法控制手中的$n"HIB"，招式不自覺的一滯………\n"NOR,me,ob);
         me->receive_damage("hp",random(200));
         me->start_busy(2);
        }
        me->receive_damage("ap",random(50));
        return;
}

int can_stab()
{
    if( query("skill_type")=="dagger" ) return 1;
    else return 0;
}
