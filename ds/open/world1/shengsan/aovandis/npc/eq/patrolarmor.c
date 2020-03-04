
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("警衛盔甲",({"patrol armor","patrol","armor"}) );
	set("long","這是一件警衛用的盔甲。\n");
	set_weight(8300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "件");
		set("value",8300);
        	set("armor_prop/armor",3);
        }
        setup();
}

int query_autoload() { return 1; }
