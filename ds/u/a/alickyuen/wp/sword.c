#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIR"可口可樂-劍"NOR, ({ "CocaCola","sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把劍刃泛青的鋒利長劍, 劍長四尺, 刃面寒光閃閃,\n"
                            "可以稱的上算是一把寶劍,是可口可樂專用武器。\n");
		set("value", 45000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "steel");
	}
    set("weapon_prop/str",1);
    set("weapon_prop/parry",9);
    set("weapon_prop/hit",5);
    set("weapon_prop/bio",1);
    set("weapon_prop/bar",1);
    set("weapon_prop/tec",1);
    set("weapon_prop/wit",1);
    set("weapon_prop/sou",1);
    init_sword(10);
    setup();
}

int query_autoload() { return 1; }