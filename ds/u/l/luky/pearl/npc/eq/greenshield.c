#include <armor.h>

inherit SHIELD;

void create()
{
set_name("綠晶盾牌",({"green shield","shield"}) );
set("long","這是由百年鋼製成的綠色盾牌, 堅硬無比。\n");
set_weight(3600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","steel");
set("unit", "面");
set("value",3960);
//set("armor_prop/defense",1);
set("limit_lv",55);
//set("armor_prop/armor",109);
 }
setup();
}
