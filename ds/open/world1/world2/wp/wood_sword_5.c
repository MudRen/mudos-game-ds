#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("木劍",({"wood sword","sword"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "wood");
	set("long",@LONG
這是一把木製短劍。
LONG);
	}
	init_sword(5);
	setup();
        set("value",300);
        set("volume", 6);
}

int query_autoload() { return 1; }
