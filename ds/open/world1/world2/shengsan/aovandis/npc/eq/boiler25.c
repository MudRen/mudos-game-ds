#include <armor.h>
inherit SHIELD;

void create()
{
	set_name("炒菜鍋",({"boiler","shield"}) );
	set("long",@LONG
這是一個不鏽鋼製的炒菜鍋。
LONG
);
	set_weight(2500);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "個");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
