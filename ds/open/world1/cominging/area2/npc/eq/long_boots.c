#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("長靴" ,({ "long boots" }) );
	set("long","一雙長長的靴子，擦的乾乾淨淨。\n");
	set_weight(1100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙" );
		set("value" ,800);
		set("armor_prop/armor", 4);
	}
	setup();
}