#include <armor.h>

inherit F_FINGER_EQ;

void create()
{
        set_name("�եɧ٫�", ({ "white jade ring", "ring" }) );
        set_weight(100);
        setup_finger_eq();
        if( !clonep() ) {
                set("unit", "�T");
                set("value",600);
                set("long", 
"�o�O�@�T�եɧ٫��A����ӫG�R�A�@�ݴN���D�O��öQ�������C\n"
                );
                set("wear_as", "finger_eq");
                set("apply_armor/finger_eq", ([
                        "con": 1,
                        "armor": 2,
                ]));
        }

        setup();
}

