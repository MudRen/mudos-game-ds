#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("普通的草靴",({"straw boots","boots"}) );
	set("long","一雙到處都買得到的草靴。\n");
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙");
		set("value",480);
	}
	setup();
}
