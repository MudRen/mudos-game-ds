#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("白色布鞋",({"white cloth boots","boots"}) );
	set("long",@LONG
這是一雙白色的布鞋。
LONG
);
	set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "雙");
	}
	set("value",430);
	set("armor_prop/armor", 5);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
