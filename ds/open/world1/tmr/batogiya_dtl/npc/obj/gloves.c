#include <armor.h>
inherit F_HAND_EQ;
void create()
{
    set_name("�p�֤�M", ({ "fur gloves" , "gloves" }) );
    set_weight(500);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 500);
        set("long", "�@���γ��~�W�p�ֻs������M�C");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 2,
        ]));
    }
    setup();
}

