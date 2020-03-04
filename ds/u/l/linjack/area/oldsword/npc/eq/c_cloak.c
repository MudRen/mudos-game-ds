#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name("披雲戴月", ({ "cloud cloak","cloak" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件衣服特製的材質和縫製方法, 讓它變成輕而強韌\n"
                           "的高防禦力衣物.\n");
		set("unit", "件");
		set("value",10000);
		set("material","cloth");
		set("limit_con",10);
		set("limit_dex",10);
	}
	set("armor_prop/dex",1);
	set("armor_prop/armor",6);
	set("armor_prop/shield",2);
	setup();
}
