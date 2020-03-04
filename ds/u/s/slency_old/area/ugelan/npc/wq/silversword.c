// sword.c : an example weapon

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW"銀  劍"NOR, ({ "silver sword","sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把由純銀所打造的劍﹐看起來十分名貴且相當有殺傷力, 然而份量卻只有二來斤左右, 適合女性配用。\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中, 閃爍出一道白光。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
    init_sword(50);
	setup();
}
