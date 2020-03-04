#include <weapon.h>
inherit BLADE;

void create()
{
set_name("天狼牙刃",({"wolf tooth blade","blade"}));
        set_weight(8850);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
相傳當年天齊二狼丸去勇闖天狼山，將天狼殺死，拔起牠的牙齒打造
了一把刀，那就是「天狼牙刃」。
LONG);
                set("unit", "把");
                set("material","blade");
        }
init_blade(55,TWO_HANDED);
set("value",5500);
set("limit_str",20);
set("limit_con",20);
set("armor_prop/str",2);
set("armor_prop/con",1);
set("wield_msg","$N從背後迅速拔出一把天牙狼刃，只見天牙狼刃冒出淡淡的藍光。\n");
set("unwield_msg", "$N將天狼牙刃插回背後刀鞘之中，感覺背後有股冰冰涼涼的寒氣。\n");
setup();
}
