#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name(HIM"甲冑"HIG"披風"NOR, ({ "corslet manteau","manteau","corslet" }) );
	set("long", "這件披風後面縫了個大大的字『武』，由此可見這是件戰鬥用的披風。\n");
	set_weight(1200);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件" );
	set("material","leather");
		set("armor_prop/armor", 6);
		set("volume",5);
		set("value", 1800);
	}
	set("wear_msg","$N從身上搜出一件$n並且把$n套在身上。\n");
	set("unequip_msg","$N以迅雷不及掩耳的速度把$n小心的放到懷中。\n");
	setup();
}
