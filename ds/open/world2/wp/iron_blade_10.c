#include <weapon.h>
inherit BLADE;

void create()
{
set_name("鐵刀",({"iron blade","blade"}));
	set_weight(6000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
這是一把熟鐵打造的刀，還算銳利。
LONG);
		set("unit", "把");
		set("material","iron");
        }
 	init_blade(10);
	setup();
        set("value",800);
}

int query_autoload() { return 1; }
