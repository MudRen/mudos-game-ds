// hairpin.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("�����Y�y", ({ "yellow cap", "cap" }));
        set_weight(200);
        setup_head_eq();
        if( !clonep() ) {
                set("unit", "��");
                set("value", 100);
                set("long", "�@���g�����F���Y�y�C\n");
                set("wear_as", "head_eq");
                set("apply_armor/head_eq/armor", 2);
        }
        setup();
}

