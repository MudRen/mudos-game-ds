// hairpin.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("�n�޴U" , ({ "peaked cap" , "cap" }));
        set_weight(500);
        setup_head_eq();
        if( !clonep() ) {
                set("unit", "��");
                set("value", 1500);
                set("long", "�o�O�@��U�����e���M����δUò���b�@�_���U�l�C\n");
                set("wear_as", "head_eq");
                set("apply_armor/head_eq/cor", 1);
        }
        setup();
}

