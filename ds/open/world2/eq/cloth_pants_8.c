#include <armor.h>
inherit PANTS;

void create()
{
	set_name("西裝褲",({ "business pants","pants" }) );
	set("long",@LONG
這是一件雜牌的黑色西裝褲。
LONG
);
	set_weight(1820);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("armor_prop/armor",8);
        setup();
        set("value",850);
        set("volume", 4);
}

int query_autoload() { return 1; }
