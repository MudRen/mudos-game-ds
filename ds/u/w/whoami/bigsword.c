#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        object me = this_player();
        int damage = me->query("level")*3/2+random(me->query("Merits/bar")*2);;        
        set_name(WHT"昊天"NOR"重劍", ({ "hao-tain sword","sword" }) );
        set_weight(90000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("material","crimsonsteel");
                set("limit_str",75);
                set("limit_int",35); 
                set("limit_dex",35);
                set("limit_con",70);  
                set("limit_lv",50);
                set("long","\n");
//                set("wield_msg", "$N從背後劍鞘中抽出一把金光閃閃的$n，握在手中當武器。\n");
//                set("unwield_msg", "$N將手中的$n插入背後劍鞘中。\n");
                set("value",0);
                set("volume",9); 
        } 
                set("weapon_prop/str", 5);
                set("weapon_prop/int", -5);
                set("weapon_prop/con", 5);
                set("weapon_prop/dex",-5); 
                set("weapon_prop/hit", -7);
                set("weapon_prop/hit", random(10));
        init_sword(damage,TWO_HANDED);
        setup();
}

void attack(object me,object victim)
{
  object ob = this_object(), 
         wp = victim->query_temp("weapon");      

        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if( me->query("class1") != "疾風門" && me->query("class2") != "疾風門" ) return;        
        
        switch( random(5) ){
         case 0:
          COMBAT_D->do_attack(me, victim, this_object(), random(5));
          COMBAT_D->report_statue(victim);  
          break;
         case 1: 
          COMBAT_D->do_attack(me, victim, this_object(), random(5));
          COMBAT_D->report_statue(victim); 
          victim->add_busy(1);
          break;  
         case 2: 
          COMBAT_D->do_attack(me, victim, this_object(), random(5));
          COMBAT_D->report_statue(victim); 
          victim->add_busy(1); 
         wp->set_durable((wp->query_durable() - random(100) ) );
          break; 
        }

        return;
}


