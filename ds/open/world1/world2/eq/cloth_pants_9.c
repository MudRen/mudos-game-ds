#include <armor.h>
inherit PANTS;

void create()
{
	set_name("大火車牛仔褲",({ "big-train jeans","jeans" }) );
	set("long",@LONG
這是一件大火車牌的深藍色牛仔長褲。
LONG
);
	set_weight(2620);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("armor_prop/armor",9);
        setup();
        set("value",1249);
        set("volume", 4);
}

int query_autoload() { return 1; }
