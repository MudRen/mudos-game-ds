#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FIST;

void create()
{
    set_name(HIR"九狐爪"NOR,({"nine-fox claw","claw"}) );
    set("long","九尾的爪子，殺傷力非常大，傳說只要配上這雙爪子，連不會武功\的平常人也可以變成英雄。\n");
        set_weight(7000);
    if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","對");
        set("value",50000); 
        set("material","gold"); 
        set("replica_ob",__DIR__"fist3");
        }
        set("wield_msg",HIW "$N雙手套上$n"HIW+"，登時$N眼中射出血紅色的殺氣，令人不由得退了二步。\n"NOR);
        set("limit_level",45);
        set("limit_str",70);
        set("limit_mks",15000);
        set("weapon_prop/dex", 2);
        set("weapon_prop/int", -2);
        set("weapon_prop/str", 3);
        set("weapon_prop/bar", 1);
        set("weapon_prop/wit", -1);

        set("weapon_prop/hit", 10);
        init_fist(70);
        setup();
}

void attack(object me,object victim)
{
        object ob = this_object();      
        int x = 1 + random(5), y, damage;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        switch( random(10) ){ // 1/10 的機率特攻
        case 0:
        message_vision(HIR"\n$N吸收了九尾妖狐的力量，狂暴了起來！！\n"NOR,me,ob); 
        for(y=0;y<x;y++){
        damage = me->query_damage();
        damage *= 1+random(3);
        damage -= victim->query_armor();
        if( damage < 0) damage = 0;
        victim -> receive_damage("hp", damage, me); 
        COMBAT_D->report_status(victim);   
        }
        break;
        }
        return;
}

