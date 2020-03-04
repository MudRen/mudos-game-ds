// cloth.c
#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
	set_name(HIC"藍藍的天專用手套"NOR,({"bluesky gloves","gloves"}));
	set("long","一雙藍藍的天專用手套。\n");
	set_weight(1900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙");
		set("material", "silver");
//		set("value",3900);
        	set("armor_prop/armor", 10);
        }
        setup();
}

int query_autoload() { return 1; }

