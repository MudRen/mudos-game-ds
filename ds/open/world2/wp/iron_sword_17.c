#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("白鐵長劍",({"whiteiron longsword","longsword","sword"}) );
	set_weight(9150);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "iron");
	set("long",@LONG
這是一把由白鐵鍛造而成的三呎長劍。
LONG);
	}
	init_sword(17);
	setup();
        set("value",2210);
        set("volume", 6);
}

int query_autoload() { return 1; }
