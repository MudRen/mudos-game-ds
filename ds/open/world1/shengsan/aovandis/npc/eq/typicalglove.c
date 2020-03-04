
#include <armor.h>
inherit HANDS;

void create()
{
	set_name("制式手套",({"typical gloves","gloves"}));
	set("long","這是奧凡迪斯守衛所裝備的手套。\n");
	set_weight(3900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙");
		set("value",4000);
		set("material", "cloth");
        	set("armor_prop/armor", 2);
        }
        setup();
}

int query_autoload() { return 1; }
