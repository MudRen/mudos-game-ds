#include <armor.h>
inherit HEAD;
void create()
{
	set_name("滿汗短襯",({ "aweat cloth","cloth" }));
	set_weight(950);
        if ( clonep() )
                set_default_object(__FILE__);
        else {       
		set("unit", "件");
		set("long", "這是一件充滿汗水的衣服。\n");
	set("material","cloth");
		set("value", 100);
		set("armor_prop/armor",3);  
	}
	setup();
}
