#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name( "烏蠶寶衣" , ({ "wu-silkworm cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 8500 );
                set("long", "這是一件用烏蠶絲做成的衣服，整件刀槍不入、水火不侵，是非常高貴的寶衣。\n");
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 5,
                        "dodge": 5,
                        "cps": 1,
                ]));
        }

        setup();
}
