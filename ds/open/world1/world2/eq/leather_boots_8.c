#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("強化皮鞋",({"adv-leather boots","boots"}) );
	set("long",@LONG
這是一雙經過強化設計的堅固皮鞋。
LONG
);
	set_weight(5200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "雙");
	}
	set("value",1140);
	set("armor_prop/armor", 8);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
