#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"�꯾�ܭ�"NOR,({ "tiger cloak","cloak" }) );
        set("long","�o��ܭ������O�Υ��B�ꪺ��֩ҽs�{�Ӧ���,\n"
                   "�Q�����[�ʡA�ӥB��_�Ӧ����̤����C\n");
        set_weight(7500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "fur");
        set("volume",3);
        set("unit", "��" );
        set("value",2800);
        set("limit_lv",15);
        set("limit_con",18);
}        
        set("armor_prop/armor",10);
        set("armor_prop/con",1);
        set("armor_prop/combat",5);
        setup();
}

