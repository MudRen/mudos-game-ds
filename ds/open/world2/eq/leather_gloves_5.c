#include <armor.h>
inherit HANDS;

void create()
{
	set_name("羊皮手套",({"sheep gloves","gloves"}));
	set("long",@LONG
這是一雙白色的羊皮長手套。
LONG);
	set_weight(620);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙");
		set("material", "leather");
        }
        set("armor_prop/armor",5);
        setup();
        set("value",570);
        set("volume", 2);
}

int query_autoload() { return 1; }
