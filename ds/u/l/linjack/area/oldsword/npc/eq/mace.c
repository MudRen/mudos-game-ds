#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
	set_name("釘頭鎚", ({ "mace" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把鎚的頭部還多了幾根刺在上面, 不知道有什麼有用的地方。\n");
		set("value", 800);
		set("material", "iron");
	}
    init_blade(13);
    setup();
}
