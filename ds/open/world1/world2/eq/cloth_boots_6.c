#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("運動鞋",({"sport boots","boots"}) );
	set("long",@LONG
這是一雙Made in Taiwan的運動鞋。
LONG
);
	set_weight(2300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "雙");
	}
	set("value",770);
	set("armor_prop/armor", 6);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
