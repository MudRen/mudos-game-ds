#include <armor.h>
inherit WAIST;

void create()
{
	set_name("軍用腰帶" ,({ "waist" }) );
	set("long","一條軍人用的腰帶，上面可以掛些東西。\n");
	set_weight(700);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "條" );
		set("value" , 1000);
		set("armor_prop/armor", 6);
		set("armor_prop/shield", 2);
	}
	setup();
}
