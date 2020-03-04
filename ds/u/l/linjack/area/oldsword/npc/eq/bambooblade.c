#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("竹刀", ({ "bamboo blade","wood" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把刀是硬竹削成，拿來練刀是不錯的用途。\n");
		set("value", 300);
		set("material", "wood");
	}
    init_blade(5);
    setup();
}
