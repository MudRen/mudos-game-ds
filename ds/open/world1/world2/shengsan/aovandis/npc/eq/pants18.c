
#include <armor.h>
inherit PANTS;

void create()
{
	set_name("運動短褲",({ "short pants","pants" }) );
	set("long",@LONG
這是一件黑色的NIKE運動褲，很適合穿來打籃球。
LONG
);
	set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("auto_set",2);
        setup();
}

//int query_autoload() { return 1; }
