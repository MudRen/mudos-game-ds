#include <armor.h>
inherit F_HAND_EQ;
void create()
{
        set_name("���s�å�", ({ "steel bracer", "bracer" }) );
        set_weight(500);
        setup_hand_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1200);
                set("long",@long
�o�O�@���ѿ��K�s�����åҡA�֦���Ϊ����m��O�C
long
                );
                set("wear_as", "hand_eq");
                set("apply_armor/hand_eq", ([
                        "armor": 3,
                        "str":1,
                        "parry":5,
                ]));
        }
        setup();
}

