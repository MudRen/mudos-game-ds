#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("籃球鞋",({"basketball boots","boots"}) );
	set("long",@LONG
這是一雙ＮＩＫＥ出品的籃球鞋。
LONG
);
	set_weight(3200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "雙");
	}
	set("value",1670);
	set("armor_prop/armor", 7);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
