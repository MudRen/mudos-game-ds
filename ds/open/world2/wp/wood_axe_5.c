#include <weapon.h>
inherit AXE;

void create()
{
        set_name("���",({"wood axe","axe"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
�o�O�@��Τ��Y�d�������Y�C
LONG);
		set("material", "wood");
	}
	init_axe(5);
	setup();
	set("value",300);
}

int query_autoload() { return 1; }
