#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIM"飛羽"HIG"甲"NOR, ({ "fly armor", "armor" , "fly" }) );
	set("long", "這復鎧甲是楊雙亟在深山中修行為方便行走所用的裝甲之一。\n");
	set_weight(7000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "副" );
		set("armor_prop/dex",    3);
	set("armor_prop/armor",18);
	set("material","steel");
		set("volume",4);
		set("limit_lv",10);
		set("limit_con",10);
	set("value", 17500);
	}
	set("wear_msg","$N一裝備上$n突然感覺輕飄飄的。\n");
	set("unequip_msg","$N一脫下$n馬上碰的一聲跌倒在地上。\n");
	setup();
}
