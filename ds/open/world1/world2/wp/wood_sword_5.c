#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("��C",({"wood sword","sword"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
	set("long",@LONG
�o�O�@���s�u�C�C
LONG);
	}
	init_sword(5);
	setup();
        set("value",300);
        set("volume", 6);
}

int query_autoload() { return 1; }
