#include <weapon.h>
inherit STAFF;

void create()
{
set_name("長棍",({"long stick","stick"}));
set("long","這是一枝長長的棍子。\n");
set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "枝");
set("value",300);
set("material","wood");
        }
init_staff(12);
        setup();
}

