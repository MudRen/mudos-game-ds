#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("�K�ԥ�", ({ "iron armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "�M");
                set("value", 800);
                set("long", 
"�o�O�@�M�g�����F�Фg���K�s���ҡA�ݱo�X�ӫD�`��T�@�ΡC\n"
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor": 12,
                                                "dodge": -10,
                        "str": 1,
                ]));
        }
        setup();
}

