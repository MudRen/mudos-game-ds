#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("�D�c", ({ "taoist sandal", "sandal" }) );
        set_weight(1300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long", "�@���D�h�`�諸�c�l, ������K�C\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/dex",1);
                set("value", 1200);
        }
        setup();
}