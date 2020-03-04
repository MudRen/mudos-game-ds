#include <armor.h>
inherit F_WAIST_EQ;

void create()
{
        set_name("古文銅腰帶", ({ "ancient belt", "belt"}) );
        set_weight(1000);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "條");
                set("value", 3000);
                set("long", "這是一條粗銅鑄造而成的腰帶，上面刻有數排古文，顯得頗有歷史價值。\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "armor": 3,
                        "int": 1,
                        "dodge": -5,
                ]));
        }

        setup();
}

