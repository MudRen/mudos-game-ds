#include <armor.h>
inherit HANDS;

void create()
{
	set_name("布套手" ,({ "cloth gloves","gloves" }));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "雙");
		set("long", "一雙用布縫成的手套, 還可以保些暖。\n");
		set("value", 125);
		set("armor_prop/armor", 2);
		set("armor_prop/shield",1);
	set("material","cloth");
	}
	setup();
}    
int query_autoload() { return 1;}
// save eq by alick
