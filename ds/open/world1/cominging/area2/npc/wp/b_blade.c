#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("大刀", ({ "big blade","blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把大刀，手把上有著些鐵鏽。\n");
		set("value", 3100);
		set("weapon_prop/damage",4);
	}
	init_blade(26);
	setup();
}
