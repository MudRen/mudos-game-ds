#include <armor.h>
inherit HEAD;

void create()
{
	set_name("雙層工作帽",({"double cloth hat","hat"}) );
	set("long",@LONG
這是一頂白色的雙層紡織工作帽。
LONG);
	set_weight(1270);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "頂");
	}
        set("armor_prop/armor",6);
        setup();
        set("value",610);
        set("volume", 2);
}
int query_autoload() { return 1; }