#include <weapon.h>

inherit AXE;

void create()
{
        set_name("短斧",({"short axe","axe"}) );
        set("long","一把不大的短斧，大半都是被拿來開山闢林用的。\n");
          set_weight(4000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
      set("value",1000);
        }
              set("wield_msg","$N握起了一隻$n當武器。\n");
          init_axe(10);
        setup();        
}
