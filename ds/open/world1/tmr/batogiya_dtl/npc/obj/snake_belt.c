#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name("�D�ָy�a", ({ "snake's skin belt", "belt"}) );
    set_weight(300);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5000);
        set("long", "�@���D�ֻs�@�Ӧ����y�a�A�W�Y��ۤ@�Ƭݤ�������r�C\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "int" : 2,
            "armor": 1,
        ]));
    }
    setup();
}
