#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("�K�l",({"iron hammer","hammer"}));
	set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",@LONG
�o�O�@��Q����w���K�l�C
LONG);
		set("unit", "��");
		set("material","iron");
        }
	init_hammer(10);
	setup();
	set("value",800);
}
