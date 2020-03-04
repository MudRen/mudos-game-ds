#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIC"藍藍的天專用項鍊"NOR,({"bluesky necklace","necklace"}));
	set("long","這是一串藍藍的天專用項鍊。/n");
	set_weight(720);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "串");
//		set("value",1800);
        	set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }

