#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIW"白色長刃"NOR, ({ "blade" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把白色的戰刃, 看來很沉重的樣子。\n");
		set("material", "steel");
		set("value",1700);
		set("limit_str",10);
	}
    set("weapon_prop/str",1);
    init_blade(20);
    setup();
}

