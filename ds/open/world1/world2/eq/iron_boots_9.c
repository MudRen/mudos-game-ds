#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("四國鐵鞋",({"fc iron boots","boots"}) );
	set("long",@LONG
這是一雙四國產業製造的鐵皮鞋，鐵製的鞋面相當容易生鏽。
LONG
);
	set_weight(5300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "雙");
	}
	set("value",1440);
	set("armor_prop/armor", 9);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
