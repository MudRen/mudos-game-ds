#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIM"鴦騫"HIG"衣"NOR, ({ "yung cloth", "cloth" }) );
	set("long", "傳說中這件衣服是紫陽山上仙人所穿的仙袍。\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件" );
		set("armor_prop/str",    1);
	set("material","cloth");
		set("armor_prop/armor",  15);
		set("value",7000);
	}
	setup();
}
