#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("短刀", ({ "kris" }) );
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把較少見的彎刀, 刀身彎曲的比普通刀來得厲害,\n"
                            "這種刀大部份都是綠林大盜在使用的。\n");
		set("value", 100);
		set("material","iron");
	}
    init_blade(13,EDGED);
    setup();
}
