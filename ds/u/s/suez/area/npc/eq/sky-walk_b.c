#include <armor.h>
inherit BOOTS;

void create()
{
set_name("�Ŧ�u",({"sky-walk boots","boots"}) );
set_weight(700);
        if( clonep() )
set_default_object(__FILE__);
        else {
set("long",
                "�@���}�G���c�l�A�H�Ū���֡A�¦⪺�c���A���u¸��\n"
                "�y�����������Ħ�F�y�L�����L���C��W�����Gı�o\n"
                "��ӤH���M��n�A�s�}�B�����ְ_�ӡC\n");


set("material", "cloth");
set("unit", "��");
set("value", 1500);

set("limit_level",10);
set("armor_prop/armor", 3);
set("armor_prop/shield", 2);
set("armor_prop/dex", 2);
set("armor_prop/int", -1);
set("armor_prop/dodge", 7);
        }
        setup();
}
