#include <armor.h>
inherit WRISTS;
void create()
{
	set_name("強力護腕", ({ "mightiness wrists", "wrists" , "mightiness" }) );
	set("long", "這是一套在平常大城市常見的護身裝備。\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("material","steel");
		set("unit", "套");
		set("armor_prop/dex",   -1);
		set("armor_prop/armor",  5);
		set("value", 790);
	}
	setup();
}
