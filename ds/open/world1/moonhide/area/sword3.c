#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name(HIC"�ɤk�C"NOR, ({ "girl sword","sword" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�ɤk�j�C[0;1;36m�[1mA[0m�W�~���S�C\n");
                set("value",34000);
                set("material", "gold");
                set("volume",5);
        set("replica_ob",__DIR__"sword4");
        }
    set("weapon_prop/str",-2);
        set("weapon_prop/dex",2);
    set("weapon_prop/hit",12);
        init_sword(60);
    setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(6)) return;        
        message_vision(HIC"�ɤk�C"HIY"�G�M�o�X�@�D"HIW"�ե� , "HIR"�w�O���ĤH���g�ӥh , �y���`�`������\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 5);
        COMBAT_D->report_statue(victim);
        victim->add_busy(1);
        return;
}

