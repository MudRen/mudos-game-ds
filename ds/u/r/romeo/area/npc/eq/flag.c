#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("���X",({ "lord's flag","flag" }) );
        set("long",
"�o���X�l�S�}�S��A�g���F���A���O�ѤW������¸�i�H�ݥX�o
���X�l���Ӫ��D�H�D��M�`�C�S���I�o�N�O�j�N�Ҥ��X����a����
�X�C���O���X���D�H�w���A�X�l�]���A���m�C���L�A�i�H�N�L�ܦb
�ӤW�A�H�L�Ѿl�����~�ӫO�@�A�C\n"
);
        set_weight(1000);
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
        set("armor_prop/int", -1);
        }
        setup();
}

