#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("精鋼刀", ({ "steel blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把尖銳的刀。\n");
		set("value", 2300);
	}
	init_blade(23);
	setup();
}
