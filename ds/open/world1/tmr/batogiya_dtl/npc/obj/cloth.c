#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("厚皮衣", ({ "fur cloth", "cloth" }) );
    set_weight(2200);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 250);
        set("long", "一件用野獸超厚皮所縫製而成的衣服。\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 2,
        ]));
    }

    setup();
}

