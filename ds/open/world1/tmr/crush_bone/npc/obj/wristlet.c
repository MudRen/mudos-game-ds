#include <armor.h>
inherit HANDS;

void create()
{
        set_name("�x���@��", ({ "army wristlet" , "wristlet" }) );
        set_weight(2000);       // �᭫���@��
        if( !clonep() ) {
                set("unit", "��");
                set("value", 300);
                set("long",@long
�o�O�@�Ӳʻɥ��y���@�áA��㭫�q�A���o���۷����m��O�C
long
                );
                set("armor_prop/armor", 5);
        } else
		   set_default_object(__FILE__);
        setup();
}

