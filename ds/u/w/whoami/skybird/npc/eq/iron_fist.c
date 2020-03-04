#include <weapon.h>

inherit FIST;

void create()
{
        set_name("鐵爪", ({ "iron claw","claw" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long", "一個常見的鐵爪。\n");
                set("material", "iron");
        }
        init_fist(4);
        set("wield_msg", "$N將鐵爪裝在手上.\n");

        set("unwield_msg", "$N將手中的$n藏入懷中。\n");

        setup();
}
