// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIG"激光劍"NOR, ({ "lightsaber","sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是"HIW"『Jedi Knight』"NOR"常用的武器。\n");
		set("value", 150000);
		set("no_sac",1);
		set("no_drop",1);
		set("no_give",1);
		set("no_get",1);
		set("no_sell",1);
		set("rigidity",500);
		set("material", "laser");
		set("wield_msg", "$N從腰上拿出一把$n,突然射出一道"HIG"激光"NOR"。\n");
		set("unwield_msg", "$N將手上的$n放回腰間。\n");
	}
    init_sword(80);
	setup();
}
int query_autoload() { return 1; }
