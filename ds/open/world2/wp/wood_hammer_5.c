#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("��l",({"wood hammer","hammer"}));
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",@LONG
�o�O�@��ܫK�y����l�C
LONG);
		set("unit", "��");
		set("material","wood");
        }
	init_hammer(5); 	// �ˮ`�O=set("weapon_prop/damage", 14);
	setup();
	set("value",300);
}
