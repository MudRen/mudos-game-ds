#include <armor.h>
inherit PANTS;
void create()
{
        set_name("�ʥ�����" ,({ "pants" }) );
        set("long","�@��A�a�H�~�|�h�諸���ǡC\n");
        set_weight(400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value" ,50);
                set("material","linen");
        }
        set("armor_prop/armor", 2);
        set("armor_prop/shield", 1); 
        setup();
}
