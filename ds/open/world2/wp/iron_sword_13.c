#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("鐵長劍",({"iron longsword","longsword","sword"}) );
	set_weight(7150);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "iron");
	set("long",@LONG
這是一把由白鐵鍛造而成的三呎長劍。
LONG);
	}
	init_sword(13);
	setup();
        set("value",1210);
        set("volume", 6);
}

int query_autoload() { return 1; }
