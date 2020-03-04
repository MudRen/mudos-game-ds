#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("布鞋", ({ "shoes" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是僅優於草鞋的腳上裝備, 十分常見簡陋.\n");
		set("unit", "雙");
		set("value",200);
		set("material","cloth");
	}
	set("armor_prop/armor",1);
	setup();
}
