#include <armor.h>
inherit SHIELD;
void create()
{
        set_name("魔力盾", ({ "magic shield","shield" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一張由魔力構成的盾牌。\n");
                set("unit", "張");
                set("no_sell",1);
                set("no_sac",1);
                set("value",900);          
                set("wear_msg", "$N的手上突然光芒四射, $n被召喚出來了!\n");
           }
        set("armor_prop/dodge",6);
        set("armor_prop/armor",15);
        setup();
}

