#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("鐵匕首",({"iron dagger","dagger"}));
	set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("material","iron");
	set("long",@LONG
這是一把由熟鐵打造而成的匕首。
LONG
);
        }
	init_dagger(10);
        setup();
        set("value",800);
	set("backstab_bonus",13);
}

int query_autoload() { return 1; }

