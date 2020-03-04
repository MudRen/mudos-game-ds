#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIY"龍蝦之劍"NOR, ({ "luky sword","sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把由龍蝦外殼所打造的絕世爛劍﹐看起來十分地脆弱。\n");
//		set("value", 100000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
//	set("weapon_prop/bar",3);
//	set("weapon_prop/bio",3);
//	set("weapon_prop/wit",3);
//	set("weapon_prop/sou",3);
//	set("weapon_prop/tec",3);
//	set("weapon_prop/str",3);
//	set("weapon_prop/int",3);
//	set("weapon_prop/con",3);
//	set("weapon_prop/dex",3);
//	set("weapon_prop/armor",300);
//	set("weapon_prop/dodge",300);
	init_sword(0);
	setup();
}

int query_autoload() { return 1; }
