#include <armor.h>
inherit HANDS;

void create()
{
	set_name("制式手套",({"typical gloves","gloves"}));
	set("long",@LONG
這是奧凡迪斯守衛所裝備的手套。
LONG
);
	set_weight(1900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "雙");
		set("material", "cloth");
        }
        set("auto_set",2);
        setup();
}

//int query_autoload() { return 1; }
