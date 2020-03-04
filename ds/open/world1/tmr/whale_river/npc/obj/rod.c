// cane.c

#include <weapon.h>

inherit F_BLUNT;

void create()
{
        set_name("釣竿", ({ "fishing rod","rod","_OBJECT_ROD_" }) );
        set_weight(1000);
        setup_blunt(1, 14, 40, 2);

        if( !clonep() ) {
                set("wield_as", ({ "blunt" }) );
                set("unit", "根");
                set("value", 250);
                set("rigidity", 12);
                set("long",
                        "一根用竹子做成的細長釣竿。\n");
        }
        setup();
}

