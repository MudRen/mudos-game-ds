#include <weapon.h>
inherit STAFF;

void create()
{
set_name("柺杖",({"walking staff","staff"}));
set("long","這是一枝老舊的木製柺杖，上面的雕花已經快被磨平。\n");
set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "枝");
        set("value",1500);
        set("material","wood");
        }
        init_staff(16,TWO_HANDED);
        setup();
}

