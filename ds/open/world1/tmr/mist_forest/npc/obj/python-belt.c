#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name("���D�y�a", ({ "python belt", "belt"}) );
        set_weight(300);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 600);
                set("long", "�o�O�@�������D�ֻs�����y�a�A���ƪ��D��W�[�F���֨��m��O�C\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "armor": 4,
                ]));
        }

        setup();
}

