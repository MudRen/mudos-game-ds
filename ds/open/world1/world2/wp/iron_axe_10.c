#include <weapon.h>
inherit AXE;

void create()
{
        set_name("�K��",({"iron axe","axe"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
�o�O�@��μ��K���y�Ӧ������Y�C
LONG);
		set("material", "iron");
	}
	init_axe(10);
	setup();
	set("value",800);
}

int query_autoload() { return 1; }
