#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
        set_name("�A�a�ɤ�",({ "beautiful-girdle","girdle" }) );
        set("long",
"   �@���}�G��´�A�A����ô�ۥɻs���a�ġC�ݰ_�Ӧ��G�O�̪�
�F��C�����D�L��Ӫ��D�H�O�֡A���O�i�H�T�w���O�L��Ӫ��D�H
�w�g���b�H�@�F�C\n"
);
        set_weight(3000);
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
        set("armor_prop/str", -1);
        }
        setup();
}

