
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("小圓盾",({"small shield","shield","small"}) );
	set("long","這是一面木製的小圓盾。\n");
	set_weight(320);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "面");
		set("value",300);
	}
	setup();
}
