#include <armor.h>

inherit HEAD;

void create()
{
    set_name("�g�q�дU", ({ "toast hat", "hat" }) );
    set_weight(500);
	set("long","�۷�u�����U�l�A�O�g�H�ڸs����g�q����a�j�Ф�U�C");

	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("volume",3);
		set("unit", "��");
		set("value", 1200);
	}
	setup();
}

