#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("鋼杖", ({ "steel staff","staff" }) );
        set_weight(9800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",@LONG
這是一把由鋼鍛造而成的的杖，相當地沉重。
LONG
);
        }
                init_staff(18);
    setup();
                set("value", 2340);
                set("volume", 6);
}

