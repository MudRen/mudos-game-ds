#include <armor.h>

inherit F_FINGER_EQ;

void create()
{
        set_name("�a������", ({ "hell earring", "earring" }) );
        set_weight(100);
        setup_finger_eq();

        if( !clonep() ) {
                set("unit", "�T");
                set("value", 5000);
                set("long",@LONG
�o�O�@�T�ι����K�ª��఩�Ұ����������C
LONG
                );
                set("wear_as", "earring_eq");
                set("apply_armor/earring_eq", ([
                        "armor" : 1,
                        "cor" : 1,
                ]));
        }

        setup();
}
