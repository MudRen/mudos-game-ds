#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("烈日鋼靴" ,({ "sun shoes","shoes" }) );
        set("long",@LONG
這是一雙火紅色的鋼製長靴，看起來相當堅固。
LONG
);
        set_weight(3200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "steel");
        set("unit", "雙" );
        set("no_sac",1);
	}
	set("value",1780);
	set("armor_prop/fire", 4); //火系防具.
	set("armor_prop/shield", 2);
	set("armor_prop/armor", 8);
        setup();
}


