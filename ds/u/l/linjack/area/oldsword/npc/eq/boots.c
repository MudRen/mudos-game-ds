#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("皮靴", ({ "skin boots","boots" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是江湖中人極其普遍的裝備之一, 平平無奇.\n");
		set("unit", "雙");
		set("value",500);
		set("material","fur");
	}
	set("armor_prop/armor",3);
	setup();
}
