#include <armor.h>
#include <ansi.h>

inherit F_ARMOR;

void create()
{
        set_name(HIW "金霜戰鎧" NOR, ({ "gold-snow armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "套");
                set("value", 15000);
                set("long",@long
    這是一件十分高級的戰鎧，由裡到外，竟全都是由純金打造，再混合
純白銀覆蓋其中，交織成密不透水的高防禦戰鎧。
long
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor":30,
                        "con": 1,
                        "str": 1,
                ]));
        }
        setup();
}
