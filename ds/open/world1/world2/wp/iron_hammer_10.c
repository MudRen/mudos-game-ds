#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("鐵槌",({"iron hammer","hammer"}));
	set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",@LONG
這是一把十分堅硬的鐵槌。
LONG);
		set("unit", "把");
		set("material","iron");
        }
	init_hammer(10);
	setup();
	set("value",800);
}
