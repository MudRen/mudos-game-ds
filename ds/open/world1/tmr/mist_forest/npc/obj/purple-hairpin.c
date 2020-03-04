// hairpin.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("紫色髮帶" ,({ "purple hairpin", "hairpin" }));
        set_weight(200);
        setup_head_eq();
        if( !clonep() ) {
                set("unit", "條");
                set("value", 1500);
                set("long",@long
這是一條淺紫色的髮帶，可以把過長的頭髮束在一起，通常是女孩子在用的。
long
                );
                set("wear_as", "head_eq");
                set("apply_armor/head_eq", ([
                        "int": 1,
                        "armor":5,
                        "str":-1,
                ]));
        }
        setup();
}

