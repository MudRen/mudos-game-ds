#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("小刀",({"dagger"}) );
        set("long","一把普通的小刀，其實只是一把匕首而已。\n");
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
      set("value",800);
        }
              set("wield_msg","$N手上一晃，拿起了一把$n當武器。\n");
          init_dagger(8);
        setup();        
}


