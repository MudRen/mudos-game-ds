#include <ansi2.h>
#include <weapon.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"神明─修羅劫"NOR,({"shiro spear","spear"}) );
        set("long",@LONG
上古霸王，修羅王所持之武器，擁有特殊的力量。
LONG
        );
        set_weight(20000);
        if (clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("unit","把");
        set("value",26000);
        set("volume",5);
        set("material","golden");
        }
        set("weapon_prop/bar",1); 
        set("weapon_prop/str",2);
        set("weapon_prop/int",-2);
        set("weapon_prop/dex",-1);
init_fork(70);
        setup();
}
void attack(object me,object victim)
{ 
        object ob=this_object();
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(10)) return; // 1/5 的機率特攻
        message_vision(HIW"$N引用天地之氣，擊向"+victim->name()+"，使得"+victim->name()+"的身體麻痺，暫時不能動了！\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);
        victim->add_busy(4);
        return;
}

