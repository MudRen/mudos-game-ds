#include <armor.h>
inherit WRISTS;
void create()
{
	set_name("纏布護腕",({"wrists"}));
	set_weight(2100);            
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "這是一件很平常的護腕。\n");
		set("value", 200);
		set("armor_prop/armor", 2);  
	set("material","cloth");
	}
	setup();
}
int query_autoload() { return 1;}
// save eq by alick
