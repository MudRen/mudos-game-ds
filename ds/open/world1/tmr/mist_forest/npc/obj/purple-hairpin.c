// hairpin.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("����v�a" ,({ "purple hairpin", "hairpin" }));
        set_weight(200);
        setup_head_eq();
        if( !clonep() ) {
                set("unit", "��");
                set("value", 1500);
                set("long",@long
�o�O�@���L���⪺�v�a�A�i�H��L�����Y�v���b�@�_�A�q�`�O�k�Ĥl�b�Ϊ��C
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

