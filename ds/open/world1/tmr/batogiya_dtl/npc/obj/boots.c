#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name("�p�־c", ({ "fur boots", "boots" }) );
    set_weight(2300);
    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 250);
        set("long", "�o�O�@���γ��~���W�p�ֻs�����c�l�C");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
          "armor": 2,
        ]));
    }
    setup();
}

