#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
	set_name(CYN"���K��"NOR, ({ "iron hammer","hammer" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",200);
		set("long", "�@�ګܤj���K��, �����ǥX�@�ѯ䦽���C\n");
		set("material", "iron");
		set("limit_str",5);
	}
    set("weapon_prop/str",1);
    init_hammer(11);
    setup();
}

