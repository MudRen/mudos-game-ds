#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("長劍", ({ "long sword", "sword" , "long" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把看起相當普通的長劍﹐份量大約有十來斤左右。\n");
		set("volume",3);
		set("value", 400);
	set("material","iron");
		set("sword",41);
	}
	set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
	set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	init_sword(15);
	setup();
}
