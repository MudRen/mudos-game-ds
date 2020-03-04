#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("大刀", ({ "weirblade","blade" }) );
	set_weight(12500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把刀總長近五尺, 份量不輕, 要雙手才能順利的揮動這把\n"
                            "大刀, 此刀為精鋼所鑄, 刃面闊而鋒利, 殺傷力不小。\n");
		set("value", 2500);
		set("material", "steel");
		set("limit_skill",15);
		set("limit_str",25);
		set("limit_con",15);
        }
    set("weapon_prop/dex",-2);
    set("weapon_prop/int",-1);
    set("weapon_prop/hit",-15);
    init_blade(40,TWO_HANDED);
    setup();
}
