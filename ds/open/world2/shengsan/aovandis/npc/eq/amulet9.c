#include <armor.h>
inherit NECK;

void create()
{
	set_name("護身符",({"amulet"}));
	set("long",@LONG
這一串紅色護身符的正面印著[南天宮]三個金色小字。
LONG
	);
	set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "串");
	}
	set("armor_prop/shield",3);
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
