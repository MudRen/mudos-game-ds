#include <armor.h>

inherit F_ARMOR;

void create()
{
        set_name("����@��", ({ "tiger-fur armor", "armor" }) );
        set_weight(15000);
        setup_armor();

        if( !clonep() ) {
    
            set("unit", "�M");
                set("value", 2000);
                set("long",@long
�o���O�@�M�ΦѪ�ְ������@�ҡA�N�W�h�D�`����T�A�����G�O��v
�s�Ӧ����ˤl�A�W�Y�ٴݯd���Ĩ��M��{���C
long
                );
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor":15,
                        "dodge": -5,
                        "con": 1,
                        "cor": 1,
                        "dex": -1,
                ]));
        }

        setup();
}

