#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name(HIM"鐮刀"HIG"手套"NOR, ({ "hook gloves","gloves","hook" }) );
	set("long","這副手套是楊雙亟山中修行為方便行走所用的裝甲之一。\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "雙" );
		set("armor_prop/armor",  5);
		set("limit_dex",14);
		set("value", 120);
	}
	set("wear_msg","$N用力的把那大手伸進$n。\n");
	set("unequip_msg","$N很用力的把手從$n中拔出來。\n");
	setup();
}
