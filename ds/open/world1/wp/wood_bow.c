#include <weapon.h>
inherit BOW;

void create()
{
        set_name("巨木弓",({"large bow","bow"}));
        set("long","這是一把橡木製的大弓，若身上有箭，可用(shoot)射出箭。\n");
        set_weight(5000);
            if( clonep() )
               set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("value",680);
        set("volume",3);
        set("material","wood");
	}
	set("monster_weapon_prop/damage", 16);
        init_bow(16);
        setup();
}