// demon_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( RED "* 霰 血 天 魔 杵 *" NOR, ({ "demon staff", "staff" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把暗紅色、兩丈多長的巨杵。\n");
		set("material", "iron");
	}
	init_staff(100);
	setup();
}
