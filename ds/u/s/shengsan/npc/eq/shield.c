#include <armor.h>
#include <ansi.h>

inherit SHIELD;

void create()
{
	set_name(HIC"藍藍的天專用盾牌"NOR,({"bluesky shield","shield"}) );
	set("long","這是由百年鋼製成的藍藍的天專用盾牌。\n");
	set_weight(5600);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "面");
//		set("value",3960);
        	set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }

