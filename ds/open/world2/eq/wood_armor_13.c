#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("硬木護甲",({"hard-wood armor","armor"}) );
	set("long",@LONG
這是一件用硬木製成的上罩式護甲。
LONG
);
     set_weight(11400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "件");
        }
        set("armor_prop/armor",13);
        setup();
         set("value",1860);
        set("volume", 8);
}

int query_autoload() { return 1; }
