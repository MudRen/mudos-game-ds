#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(HIC"藍藍的天專用頭盔"NOR,({"bluesky helm","helm"}) );
	set("long","這是藍藍的天專用頭盔。\n");
	set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "件");
//		set("value",3960);
        	set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }