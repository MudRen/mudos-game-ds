#include <armor.h>
inherit LEGGING;

void create()
{
	set_name("皮製綁腿",({"leather leggings","leggings"}) );
	set("long",@LONG
這是一雙皮製的綁腿。
LONG
);
	set_weight(1100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "雙");
	}
        set("armor_prop/armor",4);
        setup();
        set("value",480);
        set("volume", 3);
}

int query_autoload() { return 1; }
