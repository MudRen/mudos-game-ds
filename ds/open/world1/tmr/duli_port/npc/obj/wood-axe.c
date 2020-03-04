#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("木斧", ({ "wood axe","axe" }) );
        set_weight(3000);
        setup_axe(1,8,30, 4);

        if( !clonep() ) {
                set("wield_as", ({"axe","twohanded axe"}));
                set("unit", "把");
                set("value", 350);
                set("rigidity", 30);
                set("long", 
"這是一把小而巧的木製斧頭，拿來砍砍柴倒還堪使用。\n"
                );
        }
        setup();
}

