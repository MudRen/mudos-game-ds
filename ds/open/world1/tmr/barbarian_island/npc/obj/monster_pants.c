#include <armor.h>

inherit F_PANTS;

void create()
{
        set_name("���~���", ({ "monster pants", "pants" }) );
        set_weight(2500);
        setup_pants();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 300);
                set("long","�o�O�@�󤣪��Τ����~�ְ�������ǡA���M���W���O�@�i�C");
                set("wear_as", "pants");
                set("apply_armor/pants", ([
                        "armor": 2,
                ]));
        }

        setup();
}
