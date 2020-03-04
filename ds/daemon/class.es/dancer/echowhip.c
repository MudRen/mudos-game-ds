// echowhip.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name( HIM "�]�@���n" NOR, ({ "echo whip", "whip" }) );
	set_weight(17000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10000);
		set("material", "leather");
		set("rigidity", 70);
		set("wield_msg", "$N�q�y���ѤU�@��$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n��^�y���C\n");
	}
	init_whip(53);
	setup();
}
