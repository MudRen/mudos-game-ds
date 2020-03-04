// sword.c : an example weapon

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIY"金  劍"NOR, ({ "Gold sword","sword" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把由純金所打造的劍﹐看起來十分名貴且相當有殺傷力, 份量大約有十來斤左右。\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中, 感覺份量相當重。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
    init_sword(80);
	setup();
}
