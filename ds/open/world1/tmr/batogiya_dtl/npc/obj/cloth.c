#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("�p�֦�", ({ "fur cloth", "cloth" }) );
    set_weight(2200);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 250);
        set("long", "�@��γ��~�W�p�֩��_�s�Ӧ�����A�C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 2,
        ]));
    }

    setup();
}

