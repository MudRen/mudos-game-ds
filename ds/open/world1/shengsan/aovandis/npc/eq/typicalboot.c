
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("制式戰鞋",({"typical war boot","boots","typical","war"}) );
	set("long","這是奧凡迪斯守衛所裝備的戰鞋。\n");
	set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "雙");
		set("value",6000);
	}
	setup();
}
