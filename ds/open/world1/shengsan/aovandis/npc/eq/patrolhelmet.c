
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("警衛頭盔",({"patrol helmet","helmet","patrol"}) );
	set("long","這是奧凡迪斯警衛專用的頭盔。\n");
	set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "件");
		set("value",2300);
	}
	setup();
}

int query_autoload() { return 1; }
