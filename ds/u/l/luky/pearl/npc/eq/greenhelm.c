#include <armor.h>

inherit HEAD;

void create()
{
set_name("綠晶頭盔",({"green helm","helm"}) );
set("long","這是由綠水晶製成的頭盔, 十分堅固耐用。\n");
set_weight(3600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","steel");
set("unit", "件");
set("value",3960);
set("limit_lv",53);
//set("armor_prop/dodge",1);
//set("armor_prop/defense",1);
 }
setup();
}
