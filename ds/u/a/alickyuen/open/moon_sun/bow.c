#include <weapon.h>
inherit BOW;

void create()
{
	set_name("木弓", ({ "wood bow", "bow" }));
        set("long","這是一把木弓，可用(shoot)指令試著去天上的太陽描準射箭。\n");
	set_weight(1000);
            if( clonep() )
               set_default_object(__FILE__);
        else {
        set("unit", "把");
	set("value", 0);
        set("material","wood");
	}
	init_bow(1);
	set("no_put", 1);
	set("no_give", 1);
        setup();
}
