#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("鐵戰甲", ({ "iron armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "套");
                set("value", 800);
                set("long", 
"這是一套沾滿黃沙塵土的鐵製盔甲，看得出來非常堅固耐用。\n"
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor": 12,
                                                "dodge": -10,
                        "str": 1,
                ]));
        }
        setup();
}

