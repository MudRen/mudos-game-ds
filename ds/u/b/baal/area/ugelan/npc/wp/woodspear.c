#include <weapon.h>
inherit FORK;
void create()
{
        set_name("木製長矛", ({ "wooden spear", "spear"  }) );
        set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把以木頭為矛身，矛頭以鐵製成的長矛，
乃是戰爭中對付騎兵的利器...\n");
                set("volume",1);
                set("value", 150);
        set("material","wood");
        }
        setup();
}

