#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("掠雲刀",({"cloudy blade","blade"}));
	set("long","一把輕柔的大刀，當你拿起時，似乎重量比同級的大刀還要輕。\n");
	set_weight(5000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("unit", "把");
set("volume",2);
        set("material","steel");
       set("value",2250);
		set("limit_str", 10);
	}
	init_blade(35);
	setup();
}
