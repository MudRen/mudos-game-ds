#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("ĵ�β���", ({ "police armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "�M");
                set("value", 550);
                set("long", 
"�o�O�@�Mĵ�Ϊ��p�����ҡA�ѩ�ϥθ����Ū����ݧ��ơA�b���m�W�]������ĪG�C\n"
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor": 12,
                        "dodge": -5,
                        "parry": 2,
                ]));
        }

        setup();
}
