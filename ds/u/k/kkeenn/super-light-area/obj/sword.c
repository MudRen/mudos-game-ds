#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIY"光劍"NOR, ({ "light sword","sword"} ) );
        set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("volume",2);
		set("unit", "把");
	set("material","wood");
		set("long", "這是一把道士專門施法用的劍。\n");
		set("value", 10);
	}
        init_sword(15);
	setup();
}
