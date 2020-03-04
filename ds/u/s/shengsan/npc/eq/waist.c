#include <armor.h>
#include <ansi.h>

inherit WAIST;

void create()
{
	set_name(HIC"藍藍的天專用束腰"NOR,({"bluesky waist","waist"}));
	set("long","一條藍藍的天專用束腰。\n");
	set_weight(180);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit","條");
		set("material","silk");
//		set("value",1800);
        	set("armor_prop/armor", 10);
	}
	setup();
}

int query_autoload() { return 1; }

