#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("�]�~�ԥ�", ({ "evil-monster armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "�M");
                set("value", 1500);
                set("long", 
"�o���G�O�ǻ������]�~�`�諸�ԥҡA�A�i�H����Pı��ԥҤW�ǥX������C\n"
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor": 8,
                ]));
        }

        setup();
}

