#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("皮靴",({"boots"}));
	set("long","這是警察常用的皮靴。\n");
     set_weight(1500);
	if (clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","雙");
        set("value",500);           
	set("material","boots");
	set("armor_prop/armor",4);
	}
	setup();
}

