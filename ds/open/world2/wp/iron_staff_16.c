#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("八角杖", ({ "eight angle staff","staff" }) );
	set_weight(9100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
這把鐵杖長五尺，兩端各有一個八角型鐵塊。
LONG
);
		set("material", "iron");
	}
    init_staff(16);
    setup();
    set("value", 2350);
    set("volume", 6);
}

int query_autoload() { return 1; }
