#include <armor.h>
inherit HANDS;

void create()
{
	set_name("白布手套",({"white cloth gloves","gloves"}));
	set("long",@LONG
這是一雙白色的布手套。
LONG);
	set_weight(420);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙");
		set("material", "cloth");
        }
        set("armor_prop/armor",3);
        setup();
        set("value",270);
        set("volume", 2);
}

int query_autoload() { return 1; }
