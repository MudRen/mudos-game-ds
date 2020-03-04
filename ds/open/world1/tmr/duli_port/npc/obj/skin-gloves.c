#include <armor.h>
inherit F_HAND_EQ;
void create()
{
        set_name("豬牛羊皮製手套", ({ "skin gloves" , "gloves" }) );
        set_weight(500);
        setup_hand_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 2500);
                set("long",@long
這是一雙用豬、牛、羊三種動物的皮混紡而成的皮手套，雖然顏色混
雜，不怎麼美觀，但質地堅固，的確是頗高級耐用的手套。
long
                );
                set("wear_as", "hand_eq");
                set("apply_armor/hand_eq", ([
                        "armor": 1,
                        "int":1,
                ]));
        }
        setup();
}

