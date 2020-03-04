#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("老劍", ({ "old sword", "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把很舊的長劍, 有些鈍鈍的。\n");
		set("value", 500);
		set("material", "steel");
	}
	init_sword(28);

	set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
	set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");

	setup();
}
