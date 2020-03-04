#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("輕羽戰靴", ({ "feather boots", "boots" }) );
        set_weight(2000);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 5000);
                set("long",@long
    這是一雙由鳥獸類羽毛及亮鐵片編織而成的戰靴，穿在腳上可充分發
揮輕便的蹤躍能力，靴子裡頭墊有極為舒適不傷腳踝的鞋墊　
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 2,
                        "dodge": 10,
                        "dex": 1,
                ]));
        }

        setup();
}

