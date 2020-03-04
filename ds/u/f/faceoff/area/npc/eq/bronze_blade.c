#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(CYN"青銅刀"NOR, ({ "bronze blade","blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把青銅打造的巨刃。\n");
		set("material", "copper");
		set("value",1700);
		set("limit_str",13);
	}
    set("weapon_prop/con",1);
    init_blade(19);
    setup();
}

