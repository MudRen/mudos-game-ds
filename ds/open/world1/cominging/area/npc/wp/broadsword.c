#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("闊劍", ({ "broad sword" , "sword" }) );
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("material","steel");
		set("volume",3);
		set("unit", "把");
		set("long", "這是一把看起相當普通的闊劍﹐份量大約有二十來斤左右。\n");
      set("value",1000);
	}
	init_sword(25,TWO_HANDED);
	setup();
}
