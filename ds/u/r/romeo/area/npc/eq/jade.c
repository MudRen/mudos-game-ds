#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name("�Q���_��" ,({ "black-gold-jade","jade" }) );
        set_weight(900);
        set("long","�o�O�@���_�������N�A��~�o�����N�O�q�F�s�}�y�L�Ӫ�
�A���۫D�Z���N�q�C\n");
        if ( clonep() )
              set_default_object(__FILE__);
        else {
         set("material","jade");
                set("unit", "��" );
                set("value",1000);
        }
        set("armor_prop/armor", 1);
        set("armor_prop/shield", 2);
        setup();
}

