#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name("七尺大劍", ({ "great sword","sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把大劍十分巨大, 而且奇重無比, 但十分鋒利。\n");
		set("value",12500);
		set("material", "crimsonsteel");
		set("wield_msg","$N「鏘」地一聲緩緩抽出一把$n握在手中.\n");
		set("unwield_msg","$N將手中的$n緩緩收回劍鞘之中。\n");
		set("limit_skill",30);
        	set("limit_str",50);
	}
    set("weapon_prop/dex",-2);
    set("weapon_prop/parry",-5);
    set("weapon_prop/int",-2);
    set("weapon_prop/str",2);
    set("weapon_prop/hit",-5);
    init_sword(50);
    setup();
}
