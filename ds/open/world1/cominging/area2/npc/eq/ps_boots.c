#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("皮靴" ,({ "skin boots" , "boots" }) );
	set("long","用皮所做成的一雙靴子。\n");
	set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙" );
		set("value" , 260);
		set("armor_prop/armor", 3);
	}
	setup();
}
