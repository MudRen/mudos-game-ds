#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIC"木葉本之"HIW"匕"NOR, ({ "mon dagger","dagger" }) );
        set_weight(3400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","木葉村上忍用的匕首\n");
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
        message_vision(HIC"只見一到閃耀的光芒"HIW"$n"HIC"身上一刺，造成極大的刺傷。\n"NOR,me,victim); 

                                    

        COMBAT_D->do_attack(me, victim, this_object(), 6);
        COMBAT_D->report_statue(victim);
        victim->add_busy(1);
        return;
}
