#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("皮鞋",({"leather boots","boots"}) );
	set("long",@LONG
這是一雙很常見的皮鞋。
LONG
);
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "雙");
	}
	set("value",880);
	set("armor_prop/armor", 6);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
