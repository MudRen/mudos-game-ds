#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIG"暴風削"NOR, ({ "storm blade" , "blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "傳說這一把劍是一名旅客在邊疆寒冷地帶所得, 每當遇到熱水時, 就會發出隱隱的寒氣。\n");
		set("value", 4000);
		set("weapon_prop/hit",15);
	}
	set("wield_msg", "$N從繫間抽出一把$n, 剎那間似乎有些寒氣流出。\n");
	init_blade(35);
	setup();
}
