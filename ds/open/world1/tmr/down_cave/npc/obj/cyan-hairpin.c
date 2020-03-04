// hairpin.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("青色髮帶" ,({ "cyan hairpin", "hairpin" }));
        set_weight(400);
        setup_head_eq();
        if( !clonep() ) {
                set("unit", "條");
                set("value", 1800);
                set("long",@long
這是一條青色的髮帶，上頭沾滿了不少塵沙，但是編織精美秀氣。
long
                );
                set("wear_as", "head_eq");
                set("apply_armor/head_eq", ([
                        "armor": 2,
                        "str": 1,
                        "dex": -1,
                ]));
        }
        setup();
}

