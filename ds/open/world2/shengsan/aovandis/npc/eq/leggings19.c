
#include <armor.h>
inherit LEGGING;

void create()
{
	set_name("護膝",({"leggings"}) );
	set("long",@LONG
這是用來防止運動傷害的護膝。
LONG
);
	set_weight(1900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "雙");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
