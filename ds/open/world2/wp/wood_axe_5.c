#include <weapon.h>
inherit AXE;

void create()
{
        set_name("木斧",({"wood axe","axe"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
這是一把用木頭削成的斧頭。
LONG);
		set("material", "wood");
	}
	init_axe(5);
	setup();
	set("value",300);
}

int query_autoload() { return 1; }
