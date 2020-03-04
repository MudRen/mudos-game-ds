#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name("厚皮鞋", ({ "fur boots", "boots" }) );
    set_weight(2300);
    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 250);
        set("long", "這是一雙用野獸的超厚皮製成的鞋子。");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
          "armor": 2,
        ]));
    }
    setup();
}

