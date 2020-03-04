#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIY"金陽刀"NOR, ({ "sun blade","blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把金光閃閃的利刃, 是鎳與金的合金製成。\n");
		set("material", "gold");
		set("value",7000);
		set("limit_str",17);
	}
    set("weapon_prop/str",1);
    set("weapon_prop/con",2);
    init_blade(22);
    setup();
}

