#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("小刀",({"knife"}) );
	set("long","一把長僅二寸的小刀，多半是拿來護身用的。\n");
      set_weight(200);
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","把");
      set("value",500);
		set("material","iron");
	}
		set("wield_msg","$N手上一晃，不知從何拿起了一把銳利的$n\n");
		init_blade(5);
		setup();
}
