#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name(WHT"���K�C"NOR, ({ "Xian-tia sword","sword" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���K���C�A�j�����u�C\n");
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
        message_vision(HIC"$N�N�⤤��"WHT"���K�C"HIR"���������ĤH�A�h,�y���Y�������\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 5);
        COMBAT_D->report_statue(victim);
        victim->add_busy(1);
        return;
}

