#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("���оԹu", ({ "feather boots", "boots" }) );
        set_weight(2000);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 5000);
                set("long",@long
    �o�O�@���ѳ��~���Ф�ΫG�K���s´�Ӧ����Թu�A��b�}�W�i�R���o
�����K�����D��O�A�u�l���Y�Ԧ������ξA���˸}�諸�c�ԡ@
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 2,
                        "dodge": 10,
                        "dex": 1,
                ]));
        }

        setup();
}

