
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("女洋裝",({"clothes"}) );
	set("long","這是一件漂亮的洋裝。\n");
	set_weight(2300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
		set("value",870);
        }
        setup();
}

int query_autoload() { return 1; }
