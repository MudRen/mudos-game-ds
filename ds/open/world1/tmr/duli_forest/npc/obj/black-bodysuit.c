#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name("黑色緊身衣", ({ "black body suit", "suit" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 1500);
                set("long",@long
這是一件女人在穿的黑色緊身衣，你似乎還可以聞到上頭殘留下來的女人香味。
long
                );
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 3,
                        "int": 1,
                        "dex": -1,
                ]));
        }

        setup();
}

