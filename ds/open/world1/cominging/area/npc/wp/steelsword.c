#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("鋼柔劍", ({ "steel soft sword", "sword" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把輕型的軟長劍，因為韌度夠，因此常見江湖人將這類\n"
                            "的劍配在腰間當腰帶。\n");
		set("limit_skill",30);
		set("limit_dex",20);
		set("volume",2);
       set("value",2222);
		set("material", "steel");
	}
	set("wield_msg", "$N「鏗」地一聲抽出一把$n握在手中。\n");
	set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	set("weapon_prop/dex",1);
	init_sword(33);
	setup();
}
