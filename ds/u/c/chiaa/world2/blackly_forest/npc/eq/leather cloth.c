#include <armor.h>//�w�q����
#include <ansi.h>//�w�q��X
inherit CLOTH;//�j�g
void create()
{
    set_name("�֦�",({ "leather cloth","cloth" }));

      if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�H�֭��s�s�{�����q��A\n");//���㪺�ԭz
                set_weight(20);//���㪺���q  
                set("unit", "��" );//���㪺���
                set("material", "leather"); //����                 
                set("armor_prop/armor", 5); //���m�O
                set("value", 50); //����
             }
       setup();
}
