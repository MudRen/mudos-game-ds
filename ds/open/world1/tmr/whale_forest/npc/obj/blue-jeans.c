#include <armor.h>
inherit F_PANTS;
void create()
{
        set_name("深藍色牛仔褲", ({ "blue jeans", "jeans" }) );
        set_weight(900);
        setup_pants();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 900);
                set("long",@long
這是一件常見的深藍色牛仔褲，雖然價錢不高，但是耐穿實用，滿受
旅行者的喜愛。
long
                );
                  set("wear_as", "pants");
                  set("apply_armor/pants", ([
                        "armor": 2,
                ]));
        }
        setup();
}

