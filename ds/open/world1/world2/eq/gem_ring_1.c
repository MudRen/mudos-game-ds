#include <armor.h>
inherit FINGER;
void create()
{
	set_name("珠寶戒指",({"gem ring","ring"}) );
	set("long",@LONG
女人喜愛的珠寶戒指，戒面鑲了一個紅寶石。
LONG
	);
	set_weight(510);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "枚");
	}
        set("armor_prop/armor",1);
        setup();
        set("value",1500);
        set("volume", 1);
}
int query_autoload() { return 1; }

