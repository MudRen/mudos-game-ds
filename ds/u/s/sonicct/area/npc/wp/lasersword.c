#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
      set_name(HIR"激光劍"NOR,({"laser sword","sword"}));
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是市面上流行的激光劍\n");
		set("value", 5000);
		set("material", "iron");
}
     init_sword(20);
	setup();
}
