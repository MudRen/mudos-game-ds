#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("����M", ({ "steel blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@��y�U���M�C\n");
		set("value", 2300);
	}
	init_blade(23);
	setup();
}
