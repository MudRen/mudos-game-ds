#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("鐵鎚",({"hammer"}));
set("long","這是一把打鐵用的大鐵鎚。。\n");
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",300);
set("material","iron");
        }
init_hammer(15);
        setup();
}

