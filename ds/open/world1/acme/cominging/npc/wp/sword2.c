#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("長劍",({"long sword","sword"}));

	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","這是一般武林中常見的長劍。\n");
		set("unit", "把");
        set("value",1000);
		set("material","iron");
	}
	init_sword(15);
        setup();
}
