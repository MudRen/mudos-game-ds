#include <armor.h>

inherit F_FEET_EQ;

void create()
{
        set_name("���Z�u�u", ({ "barbarian boots", "boots" }) );
        set_weight(2500);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 5000);
                set("long",@long
�@�@�o�O�@�����Z�H�����Ǥ��w�[�����Ÿ˳ơA�`�O���Z�H�����Ԥh�`��
�����u�u�A�u�l�ⰼ����t�^�ۤ@�������~���A�樫�b�s�L���~����o���u�u
���K���ʯ�C
long
                );
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor": 5,
                        "dodge": 10,
                        "dex": 2,
                ]));
        }

        setup();
}

