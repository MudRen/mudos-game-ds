#include <armor.h>

inherit HEAD;

void create()
{
set_name("塔之頭盔",({"tower helm","helm"}) );
set("long","這是由銅製成的頭盔, 看起來十分堅固。\n");
set_weight(6600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","steel");
set("unit", "件");
set("value",6660);
set("limit_lv",60);
//set("armor_prop/armor",54);
//set("armor_prop/defense",2);
 }
setup();
}
