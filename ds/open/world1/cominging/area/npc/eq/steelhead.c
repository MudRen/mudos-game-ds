#include <armor.h>
inherit HEAD;
void create()
{
	set_name("鐵頭盔",({ "steel head","head" }));
	set_weight(2250);
        if ( clonep() )
                set_default_object(__FILE__);
        else {       
		set("unit", "頂");
	set("material","steel");
		set("long", "這是一頂鐵頭盔。\n");
		set("value", 220);
		set("armor_prop/armor", 2);
		set("armor_prop/shield",1);
		set("armor_prop/dex",-1);
	}
	setup();
}
int query_autoload() { return 1;}
// save eq by alick
