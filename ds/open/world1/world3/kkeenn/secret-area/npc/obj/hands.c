#include <armor.h>
inherit HANDS;
void create()
{
        set_name("大地之掌", ({ "earth hands","hands" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一隻傳說被大地的原力包圍的手掌。\n");
                set("unit", "隻");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1400);          
                set("wear_msg", "$N好像被$n祝福了, 力量暴增?!\n");
                set("unequip_msg", "$N把$n脫掉, 依舊是那隻肉雞阿。\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",4);
        setup();
}

