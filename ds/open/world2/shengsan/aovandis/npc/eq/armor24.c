#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("木製護甲",({"wood armor","armor"}) );
	set("long",@LONG
這是一件用木頭做的護甲。
LONG
);
	set_weight(2450);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "件");
        }
        set("auto_set",2);
        setup();
}

//int query_autoload() { return 1; }
