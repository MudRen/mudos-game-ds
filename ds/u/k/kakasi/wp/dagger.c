#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIC"�츭����"HIW"�P"NOR, ({ "mon dagger","dagger" }) );
        set_weight(3400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�츭���W�ԥΪ��P��\n");
                set("value",10000);

                set("material", "gold");
                set("volume",6);
}
        set("weapon_prop/str",2);
        set("weapon_prop/dex",1);
 init_dagger(61);

    setup();
}
void attack(object me,object victim)
{


        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(5)) return;
        ::attack(victim,me);
        message_vision(HIC"�u���@��{ģ�����~"HIW"$n"HIC"���W�@��A�y�����j����ˡC\n"NOR,me,victim); 

                                    

        COMBAT_D->do_attack(me, victim, this_object(), 6);
        COMBAT_D->report_statue(victim);
        victim->add_busy(1);
        return;
}
