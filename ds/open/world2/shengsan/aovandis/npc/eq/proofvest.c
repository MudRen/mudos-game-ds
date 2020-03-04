
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("警衛防彈背心",({"bullet-proof vest","vest"}) );
	set("long","這是一件警衛用的防彈背心。\n");
	set_weight(7300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "件");
		set("value",2700);
        	set("armor_prop/armor",10);
        	set("armor_prop/shield", 7);
        }
        setup();
}

int query_autoload() { return 1; }
