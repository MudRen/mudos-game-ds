#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
          set_name("�T�l�a", ({ "wolf belt", "belt","_OBJ_ID_WOLF_BELT_" }) );
        set_weight(300);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 150);
                set("long", "�o�O�@��´�����T�Ϯת��y�a�C\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                                        "cor": 1,
                ]));
        }

        setup();
}


