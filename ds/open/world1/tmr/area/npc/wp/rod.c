#include <weapon.h>

inherit WHIP;

void create()
{
    set_name("釣竿",({"fish rod","rod","fishing rod"}) );
	set("long","一枝釣魚用的普通釣竿，看來滿堅固耐用，不知用來打人會如何。\n");
      set_weight(2000);
	if (clonep() )
	 	set_default_object(__FILE__);
	else {
		set("unit","枝");
		set("volume",2);
       set("value",400);
	}
		set("wield_msg","$N拿起了一枝$n充當武器。\n");
init_whip(8);
	setup();	
}	
