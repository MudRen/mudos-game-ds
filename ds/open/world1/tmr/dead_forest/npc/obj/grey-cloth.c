#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name( "灰色上衣", ({ "grey cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 1500 );
                set("long",@long
這是一件材質頗為高級的灰色上衣，頗有保暖之效。
long
                );
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor" : 3,
                ]));
        }

        setup();
}
