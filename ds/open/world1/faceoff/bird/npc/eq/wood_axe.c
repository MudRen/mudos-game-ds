#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name("��`��", ({ "wood axe","axe" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@��ݨӫܻ������Y�C\n");
		set("material", "wood");
	}
    init_axe(5);
    setup();
}

