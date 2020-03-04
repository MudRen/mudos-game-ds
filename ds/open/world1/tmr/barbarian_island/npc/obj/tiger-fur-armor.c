#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("虎皮護甲", ({ "tiger-fur armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
    
            set("unit", "套");
                set("value", 2000);
                set("long",@long
這竟是一套用老虎皮做成的護甲，摸上去非常的堅固，但似乎是剛硝
製而成的樣子，上頭還殘留著藥味和血腥味。
long
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor":15,
                        "dodge": -5,
                        "con": 1,
                        "cor": 1,
                        "dex": -1,
                ]));
        }

        setup();
}

