// �w

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
	set_name("���K�j��", ({ "steel hammer", "hammer" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "�`");
		set("long", "�@�`���K��j�y�P��C\n");
		set("value", 2000);
        set("weapon_prop/parry", 1);
		set("material", "steel");
	}
	init_hammer(30);
	setup();
}