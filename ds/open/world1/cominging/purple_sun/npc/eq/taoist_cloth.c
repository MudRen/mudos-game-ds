#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�D�A", ({ "taoist cloth", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long", "�@��D�h�b�Ϊ��D�A. \n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 4);
                set("value", 2000);
        }
        setup();
}