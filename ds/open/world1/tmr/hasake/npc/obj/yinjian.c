// 銀匕首.c

#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name(WHT"銀匕首"NOR, ({ "silver dagger", "dagger" }));
	set_weight(1200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "這是一柄閃著亮麗銀光的匕首，十分鋒利。\n");
		set("value", 2500);
		set("material", "silver");
                 set("wield_msg", "$N手指輕晃，彈出一柄$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n放回衣袖。\n");
	}
    set("backstab_bonus",25); //百分比
	init_dagger(35);
	setup();
}
