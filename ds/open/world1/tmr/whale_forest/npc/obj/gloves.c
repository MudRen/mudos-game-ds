#include <armor.h>
inherit F_HAND_EQ;
void create()
{
        set_name("������M", ({ "floss gloves", "gloves" }) );
        set_weight(500);
        setup_hand_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 50);
                set("long",@long
�o�O�@���κ���´�����զ��M�A��Ƥ�M�F�}�@�Ӭ}�A��|�@���u
�A�w�g�ݯ}�����A���٫j�j�i�H����C
long
                );
                set("wear_as", "hand_eq");
                set("apply_armor/hand_eq", ([
                        "armor": 1,
                        "parry":1,
                ]));
        }
        setup();
}

