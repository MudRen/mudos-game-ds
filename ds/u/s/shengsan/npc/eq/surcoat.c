#include <armor.h>
#include <ansi.h>

inherit SURCOAT;

void create()
{
	set_name(HIC"藍藍的天專用外套"NOR,({"bluesky surcoat","surcoat"}) );
	set("long","這是一件藍藍的天專用外套。\n");
	set_weight(4800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "crimsonsteel");
		set("unit", "件");
//		set("value",1800);
		set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
        }
        setup();
}

int query_autoload() { return 1; }

