#include <weapon.h>

inherit WHIP;

void create()
{
    set_name("釣竿",({ "wood rod","rod" }) );
        set("long","一枝由堅木所製的釣竿比尋常釣竿耐用。\n");
      set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","枝");
                set("volume",2);
                set("value",1500);
        }
                set("wield_msg","$N拿起了一枝$n充當武器。\n");
init_whip(16);
        setup();        
}       


