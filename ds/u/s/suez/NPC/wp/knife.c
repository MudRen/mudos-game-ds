
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("小刀",({"knife"}) );
          set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("long","一把常見的小刀，並不鋒利的樣子。\n");
       set("material","iron");
              set("unit","把");
      set("value",100);
        }
              set("wield_msg","$N手上一晃，拿起了一把$n當武器。\n");
          init_dagger(1);
        setup();        
}