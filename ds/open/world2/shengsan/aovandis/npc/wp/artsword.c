#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIY"亞特長劍"NOR, ({"art longsword","longsword","sword"}) );
	set_weight(8300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把長劍﹐上面刻著「亞特」兩個字。\n");
		set("value", 4130);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
	set("weapon_prop/bar",1);
	set("weapon_prop/bio",-1);
	init_sword(20);
	setup();
}

//int query_autoload() { return 1; }
