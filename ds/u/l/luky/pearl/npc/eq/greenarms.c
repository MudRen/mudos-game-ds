#include <armor.h>
inherit WRISTS;

void create()
{
set_name("綠晶護臂",({"green arms","arms"}) );
set("long","這是以白金煉製而成的護臂,堅軔而有光澤。\n");
set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "對");
set("material", "steel");
set("value",1800);
//set("armor_prop/armor",30);
set("limit_lv",55);
 }
setup();
}
