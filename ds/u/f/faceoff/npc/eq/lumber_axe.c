#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name("劈柴鐵斧", ({ "lumber axe","axe" }) );
	set_weight(17500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這柄鐵斧已經佈滿紅鏽, 不過刃面仍異常鋒利。\n");
		set("value", 60000);
		set("material", "iron");
		set("limit_skill",20);
		set("limit_str",35);
	}
    set("weapon_prop/dex",-2);
    set("weapon_prop/con",2);
    set("weapon_prop/parry",3);
    set("weapon_prop/dodge",-3);
    init_axe(27);
    setup();
}
