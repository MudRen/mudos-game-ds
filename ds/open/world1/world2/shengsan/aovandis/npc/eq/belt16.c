#include <armor.h>
inherit WAIST;

void create()
{
	set_name("小皮帶",({"small belt","belt"}));
	set("long",@LONG
這條皮帶看起來似乎不太耐用的樣子。
LONG
	);
	set_weight(1600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "skin");
		set("unit", "條");
	}
	set("auto_set",2);
	setup();
}
// int query_autoload() { return 1; }

