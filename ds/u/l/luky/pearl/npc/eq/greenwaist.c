#include <armor.h>
inherit WAIST;

void create()
{
set_name("綠晶束腰",({"green waist","waist"}));
set("long","一條柔軟的綠色束腰。用來保護腹部及腰部不受傷害。\n");
set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit","條");
//set("wear_msg","$N將綠晶束腰綁在腰部。\n");
set("material","cloth");
//set("armor_prop/armor",7);
//set("armor_prop/dex",7);
set("value",1800);
set("limit_lv",50);
 }
setup();
}
