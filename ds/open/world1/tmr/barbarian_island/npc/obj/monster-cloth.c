#include <armor.h>

inherit F_CLOTH;

void create()
{
        set_name("���~�֦�", ({ "monster cloth", "cloth" }) );
        set_weight(2000);
        setup_cloth();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 300);
                set("long", "�o�O�@�󤣪��Τ����~�ְ������֦�C\n");
                set("wear_as", "cloth");
                set("apply_armor/cloth", ([
                        "armor": 2,
                ]));
        }

        setup();
}

