#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("八龍圓盾",({"drangon shield","shield"}) );
	set("long",@LONG
這個盾牌上的八隻巨龍正是它的特色,每隻龍都是那麼的栩栩如生，似
忽它們的靈氣已經完全灌注在這面盾上了。
LONG
	);
	set_weight(4000);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "面");
		set("value",4200);
	}
	setup();
}

int query_autoload() { return 1; }
