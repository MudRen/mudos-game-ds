#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("皮革高跟鞋",({"leather high heels","heels"}) );
	set("long",@LONG
這是一雙女性常穿的皮製高跟鞋。
LONG
);
	set_weight(2300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "雙");
	}
	set("female_only",1);
	set("value",620);
	set("armor_prop/armor", 5);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
