#include <armor.h>
inherit F_ARMOR;
void create()
{
        set_name("盔甲", ({  "armor" }) );
          set_weight(10000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 2000);
                set("long", "這是一件流傳在血腥荒野上的盔甲，常被流浪在那邊的妖魔穿載著。\n");
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                          "armor": 10,
                ]));
        }
        setup();
        set("name",
                  ENHANCE_D->enhance_armor(this_object(),0,"盔甲") );
}


