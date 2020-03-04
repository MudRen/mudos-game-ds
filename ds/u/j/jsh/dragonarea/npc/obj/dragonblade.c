#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(HIG"青龍 "HIW"長刀"NOR, ({ "green-dragon long blade","blade","long blade" }) );
        set_weight(22000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","光之子祖傳的神刀，據說是採青龍的骨頭煉成，具有神龍之奇力。\n");
                set("value",15000);
                set("volume",5);
        set("replica_ob",__DIR__"blade2");
        }
    set("weapon_prop/str",3);
        set("weapon_prop/bar",1);
    set("weapon_prop/hit",5); 
   set("weapon_prop/parry",5);   
     init_blade(67);
    setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(10)) return;        
        message_vision(HIG"青龍長刀"HIW"突然發出一陣"HIG"綠光\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 5);
        COMBAT_D->report_statue(victim);
        victim->add_busy(2);
        return;
}

