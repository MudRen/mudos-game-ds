#include <armor.h>
inherit PANTS;

void create()
{
set_name("�����",({"Golden monkey skin","skin"}) );
set_weight(2000);
        if( clonep() )
set_default_object(__FILE__);
        else {
set("long",@LONG
    �@��{�{�o���������֡A���X���Pı���A�Ԥ���K�ۥ��i�O�@��A
���O�@�K��o���֡A�Aı�o���Ѧ�{���A�ӥB�o�Ѧ�{�����A�P��Q��
���ġA�����R���F�@�ع�媺����νİʡC
LONG);


set("material", "skin");
set("unit", "�i");
set("value", 5000);

set("limit_level",20);
set("armor_prop/armor", 7);
set("armor_prop/shield", 7);
set("armor_prop/str", 2);
set("armor_prop/int", -3);
set("armor_prop/bar", 1);
        }
        setup();
}
