#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("巨刀", ({ "great blade","blade" }) );
	set_weight(35000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這刀型似三國時代關雲長用的大刀, 不過用刀者一見此刀就知其十分\n"
                            "笨重, 威力有餘, 靈盈不足, 並不適合拿來近身作戰。\n");
		set("value", 7000);
		set("material", "steel");
		set("limit_skill",15);
		set("limit_str",35);
		set("limit_con",25);
        }
    set("weapon_prop/dex",-5);
    set("weapon_prop/int",-1);
    set("weapon_prop/hit",-15);
    set("weapon_prop/dodge",-10);
    init_blade(80,TWO_HANDED);
    setup();
}
