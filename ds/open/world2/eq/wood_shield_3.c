#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("木圓盾",({"wood round shield","shield"}) );
	set("long",@LONG
這是一面大圓盾。
LONG);
	set_weight(870);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","wood");
		set("unit", "面");
	}
        set("armor_prop/armor",3);
        setup();
        set("value",210);
        set("volume", 4);
}
int query_autoload() { return 1; }
