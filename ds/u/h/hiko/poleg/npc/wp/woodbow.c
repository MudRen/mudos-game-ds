#include <weapon.h>
inherit BOW;

void create()
{
        set_name("木弓",({"wood bow","bow"}));
        set("long","這是一把木製的大弓，可用(shoot)射出箭。\n");
        set_weight(5000);
            if( clonep() )
               set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("value",850);
        set("volume",3);
        set("material","wood");
        }
        init_bow(13);
        setup();
}

