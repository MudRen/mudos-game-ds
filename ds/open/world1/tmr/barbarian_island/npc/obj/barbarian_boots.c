#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("野蠻短靴", ({ "barbarian boots", "boots" }) );
        set_weight(2500);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 5000);
                set("long",@long
　　這是一雙野蠻人村落傳之已久的高級裝備，常是野蠻人中的戰士常穿
戴的短靴，靴子兩側的邊緣鑲著一顆顆的獸牙，行走在山林野外更顯這雙短靴
輕便的性能。
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 5,
                        "dodge": 10,
                        "dex": 2,
                ]));
        }

        setup();
}

