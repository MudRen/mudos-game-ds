#include <armor.h>
inherit HANDS;

void create()
{
	set_name("工作手套",({"work gloves","gloves"}));
	set("long",@LONG
這是一雙由粗麻編成的白色工作手套。
LONG
);
	set_weight(1400);
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
