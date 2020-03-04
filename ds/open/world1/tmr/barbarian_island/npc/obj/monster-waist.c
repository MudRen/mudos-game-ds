#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name("�~�@�y�a", ({ "monster waist", "waist" }) );
        set_weight(100);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1500);
                set("long", "�o�O�@���~�@�y�a�A�O�Ψ���b�y�ڤW�Hô��Ǥl�ΡC\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "int": -1,
                        "cor": 1,
                        "parry":2,
                ]));
        }

        setup();
}

