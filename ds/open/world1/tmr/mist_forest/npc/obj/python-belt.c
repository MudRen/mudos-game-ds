#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name("蟒蛇腰帶", ({ "python belt", "belt"}) );
        set_weight(300);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "條");
                set("value", 600);
                set("long", "這是一條用蟒蛇皮製成的腰帶，光滑的蛇鱗增加了不少防禦能力。\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "armor": 4,
                ]));
        }

        setup();
}

