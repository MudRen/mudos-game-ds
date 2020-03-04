#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name("厚皮腰帶", ({ "fur belt", "belt"}) );
    set_weight(300);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "條");
        set("value", 1600);
        set("long", "這是一條利用野獸超厚皮製成的腰帶，看起來很實用。\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 2,
        ]));
    }
    setup();
}

