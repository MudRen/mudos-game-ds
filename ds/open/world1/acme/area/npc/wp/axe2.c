#include <weapon.h>
inherit AXE;

void create()
{
set_name("小手斧",({"small axe","axe"}));
set("long","這是一把相當輕巧的斧頭，用起來十分順手，也比一般斧頭來得輕。\n");
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",400);
set("volume",1);
set("material","iron");
        }
init_axe(11);
        setup();
}
int query_autoload() { return 1;} // save eq by alick
