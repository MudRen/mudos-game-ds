#include <armor.h>
inherit FINGER;

void create()
{
	set_name("兔子戒指",({"rabbit ring","ring"}) );
	set("long",@LONG
由銅打造的戒子，戒面有一個兔子的圖案。
LONG
	);
	set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "copper");
		set("unit", "枚");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
