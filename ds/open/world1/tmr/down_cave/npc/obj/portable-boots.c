#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("�����Թu", ({ "portable boots", "boots" }) );
        set_weight(1500);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 1200);
                set("long",@long
    �o�O�@���ѳn�C�����s�����Թu�A���M�����Ʀ��G�S�����򭫶q�A��
�O�ᬰ���Ū����Ƥw���Ѭ۷����m��O�C
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 3,
                        "dodge": 5,
                ]));
        }

        setup();
}

