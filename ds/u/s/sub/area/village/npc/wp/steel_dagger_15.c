#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("鋼匕首",({"steel dagger","dagger"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",@LONG
這是一把由鋼製成的匕首，為了增加傷害力所以足足有兩呎長。。
LONG
);
        }
        init_dagger(15);
        setup();
        set("value",1950);
        set("volume", 5);
        set("backstab_bonus",16);
        set("limit_dex",15);
}
