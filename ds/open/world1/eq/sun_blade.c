#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIY"�����M"NOR, ({ "sun blade","blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@������{�{���Q�b, �O��P�����X���s���C\n");
		set("material", "gold");
		set("value",7000);
		set("limit_str",17);
	}
    set("weapon_prop/str",1);
    set("weapon_prop/con",2);
    init_blade(22);
    setup();
}

