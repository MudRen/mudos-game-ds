#include <weapon.h>
inherit BLADE;

void create()
{
set_name("砍刀",({"blade"}));
set("long","這是一般武者常用的砍刀。\n");
set_weight(5000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",800);
set("volume",2);
set("material","iron");
        }
init_blade(12);
        setup();
}
int query_autoload() { return 1;} // save eq by alick
