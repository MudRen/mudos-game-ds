#include <weapon.h>
inherit BLADE;

void create()
{
set_name("大刀",({"big blade","blade"}));
set("long","這是一般武林中人常用來防身的大刀。\n");
set_weight(5000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",1600);
set("volume",5);
set("material","iron");
        }
init_blade(27);
        setup();
}
