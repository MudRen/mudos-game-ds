#include <weapon.h>
inherit AXE;

void create()
{
        set_name("鐵斧",({"iron axe","axe"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
這是一把用熟鐵打造而成的斧頭。
LONG);
		set("material", "iron");
	}
	init_axe(10);
	setup();
	set("value",800);
}

int query_autoload() { return 1; }
