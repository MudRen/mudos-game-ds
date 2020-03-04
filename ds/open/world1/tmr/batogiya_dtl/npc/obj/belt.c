#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name("�p�ָy�a", ({ "fur belt", "belt"}) );
    set_weight(300);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 1600);
        set("long", "�o�O�@���Q�γ��~�W�p�ֻs�����y�a�A�ݰ_�ӫܹ�ΡC\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 2,
        ]));
    }
    setup();
}

