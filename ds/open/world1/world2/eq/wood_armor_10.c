#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("木片護甲",({"wood armor","armor"}) );
	set("long",@LONG
這是一件用木片串成的上半身護甲。
LONG
);
	set_weight(7150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "件");
        }
        set("armor_prop/armor",10);
        setup();
        set("value",1630);
        set("volume", 8);
}

int query_autoload() { return 1; }
