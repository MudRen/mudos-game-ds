#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(HIC"藍藍的天專用靴"NOR,({"bluesky boots","boots"}) );
	set("long","一雙藍藍的天專用靴。\n");
	set_weight(360);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "wood");
		set("volume",10);
		set("unit", "雙");
		set("value",3600);
        	set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }
