#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("木杖", ({ "wood staff","staff" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
這是一把很普通的木杖。
LONG
);
		set("material", "wood");
	}
    init_staff(5);
    setup();
    set("value", 300);
    set("volume", 6);
}

int query_autoload() { return 1; }
