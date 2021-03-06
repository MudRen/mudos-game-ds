#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIW"雲藏劍"NOR, ({ "yun-tsang sword", "yun-tsang", "sword" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",
			"一把通體散發著美麗金屬光澤的長劍，把手部位雕功\細膩，\n"
			"劍柄刻著一幅流雲祥鶴，其精巧的模樣真是令人愛不釋手。\n");
		set("value", 12400);
		set("material", "silver");
		set("wield_msg", "只聽見「颼」地一聲﹐$N的手中已經多了一把光芒四射的寶劍──$n。\n");
		set("unequip_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
	init_sword(20);
	setup();
}
