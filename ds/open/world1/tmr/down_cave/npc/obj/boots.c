#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("長靴", ({"boots" }) );
        set_weight(2500);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 1500);
                set("long",@long
這是一雙流傳在血腥荒野上的長靴，常被流浪在那邊的妖魔穿載著，通
常具有奇特的能力，能使用者能獲得額外的幫助。
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 5,
                ]));
        }

        setup();
        set("name",
                  ENHANCE_D->enhance_armor(this_object(),0,"長靴") );
}

