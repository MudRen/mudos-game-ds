// sword.c : an example weapon

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("大刀", ({ "blade" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把類似常人所配帶的刀類, 不過卻大上了幾寸。\n");
		set("value", 15);
		set("material", "steel");
		set("wield_msg", "$N「從腰間拿出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n收回腰間。\n");
	}
    init_blade(30);
	setup();
}
