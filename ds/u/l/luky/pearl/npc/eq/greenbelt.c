#include <armor.h>

inherit BELT;

void create()
{
set_name("綠晶腰帶",({"green belt","belt"}) );
set_weight(3200)
;
set("long","一條亮綠色的腰帶。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "gem");
set("unit","條");
set("value",3200);
//set("armor_prop/armor",30);
set("limit_lv",49);
}
setup();
}
