#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("鋼刀",({"steel blade","blade"}));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",@LONG
這是一把鋒利的刀，刀背做的相當的厚實，相當地耐用。
LONG);
        set("unit", "把");
        }
        init_blade(20);
        setup();
        set("value",2500);
        set("volume", 6);
}
