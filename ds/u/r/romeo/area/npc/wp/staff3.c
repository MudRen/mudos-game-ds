#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("降龍杖",({"dragon staff","staff"}) );
        set("long","這是一把丈長的杖，杖身呈暗綠色，而杖頭乃雕成龍形。\n");
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
                    set("material", "blacksteel");
      set("value",1900);
        }
          init_staff(9);
        setup();
}

