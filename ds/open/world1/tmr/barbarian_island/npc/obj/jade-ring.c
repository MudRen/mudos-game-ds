#include <armor.h>

inherit F_FINGER_EQ;

void create()
{
        set_name("�ɧ�", ({ "jade ring", "ring" ,"_OBJ_ID_JADE_RING_"}) );
        set_weight(100);
        setup_finger_eq();

        if( !clonep() ) {
                set("unit", "�T");
                  set("value",0);
                set("long", 
"�o�O�@�T�a�ۨťզ⪺�ɧ٫��C\n"
                );
                set("wear_as", "finger_eq");
                set("apply_armor/finger_eq", ([
                        "int": -1,
                        "str": 1,
                ]));
        }

        setup();
}

