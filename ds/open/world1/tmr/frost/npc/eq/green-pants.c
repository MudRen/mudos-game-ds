#include <armor.h>
inherit PANTS;

void create()
{
        set_name("�C�����" ,({ "green pants","pants" }) );
        set("long",@LONG
�o�O�@��C�h�����s´�Ӧ������ǡA����������Ŧ��_�u�}�n�C
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",600);
        }
        set("armor_prop/armor",4);
        setup();
}

