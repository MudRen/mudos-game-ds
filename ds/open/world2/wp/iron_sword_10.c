#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("鐵劍",({"iron sword","sword"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "iron");
	set("long",@LONG
這是一把由鐵熟鐵打造而成的劍。
LONG);
	}
	init_sword(10);
	setup();
        set("value",800);
        set("volume", 6);
}

int query_autoload() { return 1; }
