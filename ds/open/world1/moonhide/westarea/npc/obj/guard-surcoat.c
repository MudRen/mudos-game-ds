#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
        set_name("�v��̩ܭ�",({ "sun-follow surcoat","surcoat" }) );
        set("long","�o�O���ι��º����谵�����ܭ��A����X�n�A�N�_�Ӥ���ΪA�C\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","silk");
                set("unit", "��" );
                set("value",500);
        }  
        set("armor_prop/armor", 5); 
        set("armor_prop/dex", 1);
        setup();
}

