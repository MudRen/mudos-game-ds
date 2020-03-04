#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIR"四靈修羅劍"NOR, ({ "four shura sword","sword" }) );
	set_weight(17500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把長劍相傳是四靈劍之首, 是由四靈劍王親手所製, 蘊藏靈氣。\n");
		set("value", 6000);
		set("material", "crimsonsteel");
		set("wield_msg",HIW"$N「鏘」地一聲抽出一把$n握在手中, 頓時昊光萬丈!\n"NOR);
		set("unwield_msg",CYN"$N將手中的$n收回劍鞘之中, 四周光芒漸漸暗淡。\n");
		set("limit_skill",75);
		set("limit_int",45);
		set("limit_dex",45);
		set("weapon_prop/dex",3);
		set("weapon_prop/con",3);
		set("weapon_prop/parry",10);
		set("weapon_prop/int",3);
		set("weapon_prop/str",3);
		set("weapon_prop/hit",10);
	}
    init_sword(125);
    setup();
}
