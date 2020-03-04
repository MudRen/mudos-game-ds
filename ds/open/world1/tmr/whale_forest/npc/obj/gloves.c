#include <armor.h>
inherit F_HAND_EQ;
void create()
{
        set_name("綿布手套", ({ "floss gloves", "gloves" }) );
        set_weight(500);
        setup_hand_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 50);
                set("long",@long
這是一雙用綿布織成的白色手套，整副手套東破一個洞，西漏一條線
，已經殘破不堪，但還勉強可以穿載。
long
                );
                set("wear_as", "hand_eq");
                set("apply_armor/hand_eq", ([
                        "armor": 1,
                        "parry":1,
                ]));
        }
        setup();
}

