#include <weapon.h>
inherit AXE;

void create()
{
        set_name("制式戰鎚",({"typical axe","typical","axe"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "這是一支奧凡迪斯守衛的制式戰鎚。\n");
		set("value", 5000);
		set("material", "steel");
	}
	init_axe(32);
	setup();
}

int query_autoload() { return 1; }
