#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("彎刀", ({ "cutless" }) );
	set_weight(5500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把較少見的彎刀, 刀身彎曲的比普通刀來得厲害,\n"
                            "這種刀大部份都是綠林大盜在使用的。\n");
		set("value", 500);
		set("material","steel");
		set("limit_skill",25);
		set("limit_dex",10);
	}
    set("weapon_prop/hit",20);
    init_blade(25);
    setup();
}
