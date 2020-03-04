#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("銀色短刀", ({ "silver kris","kris" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "這把短刀刃部泛淡淡銀光, 而且刃部十分鋒利\n"
                            ", 看起來手工相當細膩, 適合拿來近身突擊用。\n");
		set("needaward",5);
		set("material", "silver");
	set("value",1);
	}
    set("weapon_prop/hit",40);
    set("weapon_prop/int",1);
    set("weapon_prop/dex",2);
	init_blade(25);
    setup();
}

int query_autoload() { return 1; }
