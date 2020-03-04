#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name("腰帶", ({ "belt"}) );
        set_weight(300);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "條");
                set("value", 2000);
                set("long", "這是一條流傳在血腥荒野上的腰帶，常被流浪在那邊的妖魔穿載著。\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "armor": 2,
                ]));
        }
        setup();
        set("name",
                  ENHANCE_D->enhance_armor(this_object(),0,"腰帶") );
}

