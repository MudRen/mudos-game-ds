#include <armor.h>
inherit HEAD;

void create()
{
	set_name("廚師帽",({"cook hat","hat"}) );
	set("long",@LONG
這是一頂白色長型的廚師帽。
LONG);
	set_weight(1100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "頂");
	}
        set("armor_prop/armor",5);
        setup();
        set("value",435);
        set("volume", 2);
}
int query_autoload() { return 1; }