#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�}����" ,({ "junk cloth" , "cloth" }) );
        set("long","�|��o�ئ�A�����O�^���N�O�Ƥl..�C\n");
        set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value" , 5);
                set("material","cloth");
        }
        set("armor_prop/armor", 1);
        set("armor_prop/shield", 1);
        set("armor_prop/int", -1); 
        setup();
}
