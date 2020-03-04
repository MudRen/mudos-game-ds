#include <weapon.h>

inherit F_PIKE;

void create()
{
        set_name("短槍", ({ "short pike", "pike" }) );
        set_weight(3500);
        setup_pike(1, 9, 60, 3);

        if( !clonep() ) {
                set("wield_as", ({"pike","secondhand pike"}));
                set("unit", "把");
                set("value", 250);
                set("rigidity", 30);
                set("long", "這是一枝生鐵做的短槍，大概打鐵的功力不夠，槍頭有點鈍鈍的。\n");
        }
        setup();
}


