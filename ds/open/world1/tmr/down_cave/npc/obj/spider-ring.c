#include <armor.h>

inherit F_FINGER_EQ;

void create()
{
        set_name("�j��٫�", ({ "spider ring", "ring","_QUEST_ITEM_WIRE_NINA_" }) );
        set_weight(100);
        setup_finger_eq();

        if( !clonep() ) {
                set("unit", "�T");
                set("value", 8000 );
                set("long", 
"�o�O�@�T�j��y�����٫��A�A�J�ӺݸԡA�o���M�oı�O�Q���}���j��ˤl�C\n"
                );
                set("wear_as", "finger_eq");
                set("apply_armor/finger_eq", ([
                        "armor": 2,
                        "cor": 1,
                ]));
        }

        setup();
}

