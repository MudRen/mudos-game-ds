#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("砍刀", ({ "Claymore","blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這種刀在江湖上十分常見, 通常是官兵或侍衛常佩戴的兵器。\n");
		set("value", 1500);
		set("material", "steel");
		set("limit_skill",25);
		set("limit_str",10);
		}
    set("weapon_prop/hit",10);
    init_blade(25);
    setup();
}
