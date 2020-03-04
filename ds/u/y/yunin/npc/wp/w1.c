#include <ansi.h>

#include <weapon.h>

inherit SWORD;



void create() {

        set_name(HIR"ψ"NOR""BLU"月"NOR""MAG"狼"HIB"斬"HIM"妖"HIW"劍"NOR,({"moon sword","sword"}));

        set("long",@LONG

天界第一猛將所持的劍。

LONG

);

        set_weight(9000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

        set("limit_dex",20);

        set("limit_skill",30);

        set("unit", "把");

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

        message_vision(HIR"$N手中的月狼斬妖劍突然出現數道真氣並且往敵人身上衝去\n"NOR,me);

        COMBAT_D->do_attack(me, victim, this_object(), 4);

        COMBAT_D->report_statue(victim);

        victim->add_busy(1);

        return;

}
