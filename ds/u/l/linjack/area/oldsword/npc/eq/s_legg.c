#include <armor.h>
inherit LEGGING;
void create()
{
	set_name("銀絲護腿", ({ "steel leggings","leggings" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一雙包有層層銀絲的護腿, 可以提供一定的防禦力。\n");
		set("unit", "雙");
		set("value",1500);
		set("material", "steel");
		set("limit_con",15);
	}
	set("armor_prop/armor",4);
	set("armor_prop/shield",2);
	set("armor_prop/dex",1);
	setup();
}
