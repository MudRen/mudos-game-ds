#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
        set_name(HIR"燃燒之手"NOR,({"burning hands","hands","hand","fist"}) );
        set ("long", @LONG
這是一對紅橙色的手套，隱隱發出火光之色，讓人有種敬畏的
感覺。據說這是300年曾有一位邪惡的法師在此手套上附魔強
大的咒文，具有神秘的黑暗力量。
LONG
);
        set_weight(1000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","對");
        set("value",3500);
        set("material","fur");
        set("no_drop",1);
        }

        set("weapon_prop/bar",1);
        set("weapon_prop/wit",1);
        set("weapon_prop/sou",1);
        set("weapon_prop/bio",-1);
        set("weapon_prop/tec",-2);
        set("weapon_prop/con",2);
      init_fist(35);
        setup();
set("wield_msg", HIR"$N緩緩戴上一對$n"HIR"，忽然一陣熱氣從$N"HIR"手心奔騰出來，令人退卻。\n"NOR);
}


//我不知道特攻怎麼寫...so...再研究... :P
