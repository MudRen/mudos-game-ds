#include <ansi.h>

#include <weapon.h>

inherit SWORD;



void create() {

        set_name(HIR"�r"NOR""BLU"��"NOR""MAG"�T"HIB"��"HIM"��"HIW"�C"NOR,({"moon sword","sword"}));

        set("long",@LONG

�ѬɲĤ@�r�N�ҫ����C�C

LONG

);

        set_weight(9000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

        set("limit_dex",20);

        set("limit_skill",30);

        set("unit", "��");

        set("value",10000);

        set("volume",4);

        set("material","steel");

              }

        init_sword(70);

        setup();



}



void attack(object me,object victim)

{

        ::attack();

        if(!me) return;

        if(!victim) return;

        if(me->is_busy()) return;

        if(random(3)) return; // 

        message_vision(HIR"$N�⤤����T�٧��C��M�X�{�ƹD�u��åB���ĤH���W�ĥh\n"NOR,me);

        COMBAT_D->do_attack(me, victim, this_object(), 4);

        COMBAT_D->report_statue(victim);

        victim->add_busy(1);

        return;

}
