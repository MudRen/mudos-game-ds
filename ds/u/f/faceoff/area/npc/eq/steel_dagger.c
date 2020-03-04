#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("烏鋼匕首", ({ "black steel dagger","dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把以烏鋼打造的匕首, 看來相當銳利。\n");
                set("material", "blacksteel");
        }
        init_dagger(22);
        set("wield_msg", "$N從懷中摸出一把$n握在手中。\n");

        set("unwield_msg", "$N將手中的$n藏入懷中。\n");

        setup();
}
