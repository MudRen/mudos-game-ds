#include <armor.h>

inherit FINGER;

void create()
{
set_name("綠晶戒指",({"green ring","ring"}) );
set("long","這枚戒指上面鑲了一顆美麗的綠色水晶。\n");
set_weight(2800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "gem");
set("unit", "枚");
set("value",3980);
set("armor_prop/wis",1);
//set("armor_prop/armor",23);
set("limit_lv",50);
}
setup();
}
