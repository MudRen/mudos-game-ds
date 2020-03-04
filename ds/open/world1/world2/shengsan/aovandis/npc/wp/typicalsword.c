#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("制式長劍",({"typical long sword","long sword","sword"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把奧凡迪斯守衛的制式長劍。\n");
		set("value", 5000);
		set("material", "steel");
	}
	init_sword(15);
	setup();
}

int query_autoload() { return 1; }
