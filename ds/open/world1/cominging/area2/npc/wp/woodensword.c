#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("木劍", ({ "wooden sword" , "sword" }) );
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把道士專門施法用的劍。\n");
		set("value", 10);
	}
	init_sword(1);
	setup();
}
