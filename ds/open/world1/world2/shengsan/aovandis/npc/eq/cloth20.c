#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("運動衫",({"sport clothes","clothes"}) );
	set("long",@LONG
這是一件愛迪達生產的運動休閒衫。
LONG
);
	set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
	set("auto_set",2);
        setup();
}

// int query_autoload() { return 1; }
