
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("紅琉璃戒指",({"red glazed ring","ring","red","glazed"}) );
	set("long",@LONG
這個戒指有著紅色的韻味，你看出美麗的紅色琉璃是這只戒指的靈魂所在。
LONG
	);
	set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "枚");
		set("value",1650);
	}
	setup();
}
