#include <armor.h>
inherit F_HAND_EQ;
void create()
{
        set_name("�ޤ��ϥֻs��M", ({ "skin gloves" , "gloves" }) );
        set_weight(500);
        setup_hand_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 2500);
                set("long",@long
�o�O�@���νޡB���B�ϤT�ذʪ����ֲV���Ӧ����֤�M�A���M�C��V
���A�������[�A����a��T�A���T�O�ᰪ�ŭ@�Ϊ���M�C
long
                );
                set("wear_as", "hand_eq");
                set("apply_armor/hand_eq", ([
                        "armor": 1,
                        "int":1,
                ]));
        }
        setup();
}

