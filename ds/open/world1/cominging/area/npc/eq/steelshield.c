#include <armor.h>
inherit SHIELD;

void create()
{
	set_name("鋼鐵護盾",({"steel shield","shield"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("volume",4);
		set("long", "這是一塊常見的盾牌。\n");
		set("value",400);
	set("material","steel");
	}
	set("armor_prop/armor",3);
	setup();
}    

int query_autoload() { return 1;}
// save eq by alick
