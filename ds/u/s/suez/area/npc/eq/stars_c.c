#include <armor.h>

inherit CLOTH;

void create()
{
set_name("�s�P�q��",({"stars cloth","cloth"}) );

set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","�¦⪺��ƤW���۲ӷL���}�աA�ȥզ⪺���̥�\n"
                "�դ����o�X�L�z�����~�A�����F�R���P�P���]��\n"
                "�Cť���o�س]�p����ª��]���󤣤ޤH�`�ءA\n"
                "�ϱo�j�������s�鳣�Q�����w�Υ��C"
);
set("material", "cloth");
set("unit", "��");
set("value",500);

set("armor_prop/armor", 5);
set("armor_prop/shield", 2);

        }
        setup();
}
