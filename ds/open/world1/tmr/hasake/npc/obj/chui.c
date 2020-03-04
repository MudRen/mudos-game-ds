// 針

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
	set_name("精鐵大錘", ({ "steel hammer", "hammer" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄精鐵制的大流星錘。\n");
		set("value", 2000);
        set("weapon_prop/parry", 1);
		set("material", "steel");
	}
	init_hammer(30);
	setup();
}