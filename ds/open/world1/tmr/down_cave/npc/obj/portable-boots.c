#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("輕捷戰靴", ({ "portable boots", "boots" }) );
        set_weight(1500);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 1200);
                set("long",@long
    這是一雙由軟青絲布製成的戰靴，雖然輕飄飄似乎沒有什麼重量，但
是頗為高級的布料已提供相當的防禦能力。
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 3,
                        "dodge": 5,
                ]));
        }

        setup();
}

