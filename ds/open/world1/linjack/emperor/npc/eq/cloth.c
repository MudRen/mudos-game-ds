#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�ʥ��u�m" ,({ "short cloth" , "cloth" }) );
        set("long","�@��Q���`�����u�m�C\n");
        set_weight(400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value" ,50);
                set("material","linen");
        }
        set("armor_prop/armor", 3);
        set("armor_prop/shield", 2); 
        setup();
}
