// hairpin.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("鴨舌帽" , ({ "peaked cap" , "cap" }));
        set_weight(500);
        setup_head_eq();
        if( !clonep() ) {
                set("unit", "件");
                set("value", 1500);
                set("long", "這是一件帽頂的前部和月牙形帽簷扣在一起的帽子。\n");
                set("wear_as", "head_eq");
                set("apply_armor/head_eq/cor", 1);
        }
        setup();
}

