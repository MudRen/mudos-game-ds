#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
        set_name("�����K�������v", ({ "helatiesi ocean necklace","necklace"}) );
        set_weight(1500);
        setup_neck_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 15000);
                set("long",@long
�o�O�@���ݰ_�ӫD�`�öQ������A���媺�Y�l�O�@���������J�j�p��
���_�ۡA���o���_�۪��j�p�A�N�i��X���ֻ����C�M���_�ۤW���G���Ʊ�
�����A��������z���G�s´���Y�ؤ�r�A�����M�z�S�۴��z���{�H�C
long
        );
                set("wear_as", "neck_eq");
                set("apply_armor/neck_eq", ([
                        "int": 2,
                         "cor": -2,
                        "armor":2,
                ]));
        }
        setup();
}

