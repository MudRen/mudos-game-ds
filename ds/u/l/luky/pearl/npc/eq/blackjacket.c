#include <armor.h>

inherit SURCOAT;

void create()
{
set_name("黑皮夾克",({"black jacket","jacket"}) );
set("long","這是一件羊皮製成的黑色皮夾克。外層還上了一層亮油。\n");
set_weight(1275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "件");
set("value",1275);
//set("armor_prop/armor",12);
set("limit_lv",25);
        }
        setup();
}
