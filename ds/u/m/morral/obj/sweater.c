#include <armor.h>

inherit SURCOAT;

void create()
{
set_name("毛衣",({"sweater"}) );
set("long"," 這是一件很保暖的毛衣。\n");
set_weight(750);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "fur");
set("unit", "副");
                set("value", 1130);
set("armor_prop/armor",15);
set("armor_prop/defense",1);
set("level",15);
}
setup();
}
