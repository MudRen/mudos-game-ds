#include <armor.h>

inherit F_ARMOR;

void create()
{
    set_name("�C���@��", ({ "bronze armor", "armor" }) );
    set_weight(11000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 600);
        set("long", "�@��C�ɻs�����@�ҡA�ݰ_�Ӭ۷�I���A���O�i�H�O�@�A���ͩR�w���C");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
        ]));
    }

    setup();
}

