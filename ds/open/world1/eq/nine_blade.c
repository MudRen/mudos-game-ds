#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("九環刃", ({ "blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把刀背上掛有九個圓環的刀, 相當適合江湖人士使用。\n");
		set("material", "blacksteel");
		set("value",2000);
		set("limit_str",10);
	}
    set("weapon_prop/str",2);
    init_blade(20);
    setup();
}

