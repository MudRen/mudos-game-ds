#include <ansi.h>
#include <weapon.h>  
inherit DAGGER; 
void create()
{
        set_name(WHT"鐵匕首"NOR, ({ "iron dagger" , "dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "把");
                set("long", "一把用鐵鑄成的匕首。\n");
                set("value", 3000);
        }
        init_dagger(50);
        setup();
}

