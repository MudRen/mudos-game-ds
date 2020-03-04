#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name("武道服", ({ "fighter cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 250);
                set("long", "一件胸口繡有「銀刀」字樣的武鬥服，質地摸起來非常的舒服。\n");
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 4,
                ]));
        }

        setup();
}


