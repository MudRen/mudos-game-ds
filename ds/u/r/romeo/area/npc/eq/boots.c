#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name("�j���u",({ "qua-foo-boots","boots" }) );
        set("long",
"�o�ӹu�l���`���j�A�]���`�����C�W���H�K���^�X�j���l�骺�ǻ�
�C���O�K�֤w�ͤF�@�h�������áC�O���~���w�b������ҳy�����A��
�L�j���l�v���Ӷ��o�̵M�{ģ�۪��ݥ��A�C\n"
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/int", -2);
        set("armor_prop/dex", 1);
        }
        setup();
}

