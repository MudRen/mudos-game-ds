#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("道服", ({ "taoist cloth", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long", "一件道士在用的道服. \n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 4);
                set("value", 2000);
        }
        setup();
}