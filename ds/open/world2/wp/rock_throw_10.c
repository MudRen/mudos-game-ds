#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("���Y",({"stone"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	        set("base_unit", "��");
	        set("unit", "��");
		set("base_volume",1);
		set("base_weight",300);
		set("material", "rock");
	set("long",@LONG
�@�����J��j�p�����Y�C
LONG);
	}
	init_throwing(10);
	setup();
        set("value",30);
        set("volume", 1);
        set_amount(1);
}
