#include <armor.h>
inherit LEGGING;

void create()
{
	set_name("強化鐵護腿",({"adv-iron leggings","leggings"}) );
	set("long",@LONG
這一雙鋼鐵鍛造的側開式護腿經過了強化處理。
LONG
);
	set_weight(2800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "雙");
	}
        set("armor_prop/armor",8);
        setup();
        set("value",1420);
        set("volume", 4);
}

int query_autoload() { return 1; }
