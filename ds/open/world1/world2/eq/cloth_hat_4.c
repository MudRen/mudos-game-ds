#include <armor.h>
inherit HEAD;

void create()
{
	set_name("藍色工作帽",({"blue cloth hat","hat"}) );
	set("long",@LONG
這是一頂藍色的工作帽。
LONG);
	set_weight(970);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "頂");
	}
        set("armor_prop/armor",4);
        setup();
        set("value",325);
        set("volume", 2);
}
int query_autoload() { return 1; }