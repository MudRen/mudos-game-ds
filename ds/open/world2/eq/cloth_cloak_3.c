#include <armor.h>
inherit SURCOAT;

void create()
{
	set_name("大浴巾",({"bath towel","towel"}) );
	set("long",@LONG
這是一件米白色的大浴巾。
LONG
);
	set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "雙");
	}
	set("value",580);
	set("armor_prop/armor", 3);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
