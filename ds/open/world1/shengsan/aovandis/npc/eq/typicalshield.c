
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("制式盾牌",({"typical shield","shield","typical"}) );
	set("long","這是奧凡迪斯守衛所裝備的盾牌。\n");
	set_weight(6600);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "面");
		set("value",6960);
	}
	setup();
}
