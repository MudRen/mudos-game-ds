#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("�}�¯�c", ({ "old sandal", "sandal" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/dex",1);
                set("value", 1000);
        }
        setup();
}