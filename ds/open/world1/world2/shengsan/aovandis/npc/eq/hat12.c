#include <armor.h>
inherit HEAD;

void create()
{
	set_name("休閒帽",({"hat"}) );
	set("long",@LONG
這種藍白相間的休閒帽現在已經不流行了。
LONG
);
	set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "頂");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
