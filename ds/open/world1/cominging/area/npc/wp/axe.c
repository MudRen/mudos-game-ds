#include <weapon.h>
inherit AXE;
void create()
{
	set_name("斧頭", ({ "middle axe", "axe" }) );
	set("long",
		"一把專門開山砍樹的斧頭。\n"
	);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
       set("value",700);
		set("matreial", "iron" );
		set("volume",3);
	}
	init_axe(15);
	set("wield_msg", "$N把腰中的斧頭用手舉了起來。\n");
	set("unwield_msg", "$N將手中的斧頭放入腰上。\n");
	setup();
}
