#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("戶政官官服" ,({ "ossifer's cloth","cloth" }) );
	set("long","這件是戶政官平常所穿著的一套衣服。\n");
	set_weight(1200);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",2);
		set("material", "cloth");
		set("unit", "件" );
		set("value", 700);
	}
	set("armor_prop/armor", 6);
	setup();
}
