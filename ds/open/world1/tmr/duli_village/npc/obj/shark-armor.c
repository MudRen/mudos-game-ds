#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("�T�ֲ���", ({ "shark armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "�M");
                set("value", 1000);
                set("long", 
"�o�O�@�M���T���ְ��������ҡA�A�ٻD�o��W�Y�ݯd����{���C\n"
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor": 15,
                        "dodge": -10,
                        "str":1,
                        "dex":-1,
                ]));
        }

        setup();
}

