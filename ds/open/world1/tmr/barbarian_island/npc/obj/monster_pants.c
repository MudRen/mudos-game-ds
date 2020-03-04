#include <armor.h>

inherit F_PANTS;

void create()
{
        set_name("野獸毛褲", ({ "monster pants", "pants" }) );
        set_weight(2500);
        setup_pants();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 300);
                set("long","這是一件不知用什麼野獸皮做成的毛褲，雖然粗糙但是耐磨。");
                set("wear_as", "pants");
                set("apply_armor/pants", ([
                        "armor": 2,
                ]));
        }

        setup();
}
