#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("手杖",({"staff"}) );
        set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
         set("long","裝飾華麗的手杖，是用來顯示權利、財富、以及自大的道具。\n");
         set("material","iron");
         set("unit","把");
         set("value",2000);
        }
        set("wield_msg","$N悠閒的將$n拿了起來。\n");
        init_staff(10);
        setup();        
}

