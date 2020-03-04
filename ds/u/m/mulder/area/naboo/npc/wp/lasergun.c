#include <weapon.h>
#include <ansi.h>

inherit GUN;

void create()
{      
	set_name(HIB"激光槍"NOR,({"laser gun","gun"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",HIG"這是一把激光槍。\n"NOR);
        set("value",2100);
        set("bullet_type","energy");
        set("max_load",20);
        init_gun(10);
        set("material", "iron");
        setup();
        }
}
