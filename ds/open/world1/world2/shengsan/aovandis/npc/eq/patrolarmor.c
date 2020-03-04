
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("警衛盔甲",({"patrol armor","armor"}) );
	set("long","這是一件警衛用的盔甲。\n");
	set_weight(8600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "件");
		set("value",2360);
        	set("armor_prop/armor",13);
        }
        setup();
}

int query_autoload() { return 1; }
