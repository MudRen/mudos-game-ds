#include <weapon.h>

inherit AXE;

void create()
{
        set_name("巨斧", ({ "huge axe","axe"}) );
        set_weight(10000);
        init_axe(45);

        if( !clonep() ) {
                set("unit", "把");
                set("value", 3500);
                set("rigidity", 80);
                set("long",@long
    這是一把巨大且沉重的巨斧，沒有相當臂力的人，幾乎是拿不動的。
long
                );
        }  else
		   set_default_object(__FILE__);
        setup();
}

