#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("刺刀", ({ "stab blade" }) );
	set_weight(2100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把聽說專人刺殺人用的刀。\n");
		set("value", 1200);
	}
	init_blade(24);
	setup();
}
