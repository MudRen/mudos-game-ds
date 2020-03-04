#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
         set_name(WHT"玄鐵劍"NOR, ({ "xian-tia sword","sword" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","玄鐵重劍，大巧不工。\n");
                set("value",10000);
                set("volume",5);
        set("replica_ob",__DIR__"sword2");
        }
    set("weapon_prop/str",3);
        set("weapon_prop/dex",-2);
    set("weapon_prop/hit",10);
        init_sword(65);
    setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(6)) return;        
        message_vision(HIC"$N將手中的"WHT"玄鐵劍"HIR"狠狠的往敵人劈去,造成嚴重的瘀傷\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 5);
        COMBAT_D->report_statue(victim);
        victim->add_busy(1);
        return;
}

