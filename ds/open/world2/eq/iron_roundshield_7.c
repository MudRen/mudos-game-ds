#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("鐵圓盾",({"iron round shield","shield"}) );
	set("long",@LONG
這是一面大圓盾。
LONG);
	set_weight(2370);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","wood");
		set("unit", "面");
	}
        set("armor_prop/armor",7);
        setup();
        set("value",1810);
        set("volume", 6);
}
int query_autoload() { return 1; }
