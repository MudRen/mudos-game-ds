#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name("麻布手套", ({ "gloves" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","通常戴這雙手套, 一定是常常手持重物, 為了保護手減少磨擦\n"
			   "受傷而戴的, 不過老實講穿這種沒彈性的手套, 手也不很舒服....\n");
		set("unit", "雙");
		set("value",200);
		set("material","fur");
	}
	set("armor_prop/armor",1);
	set("armor_prop/parry",5);
	setup();
}
