#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("木法劍", ({ "wood magic sword", "sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把施法用的木劍, 上面還刻有些圖案。\n");
		set("value", 1100);
		set("material", "wood");
	}
	init_sword(27);

	set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
	set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");

	setup();
}
