#include <weapon.h>

inherit FIST;

void create()
{
        set_name("修羅血掌",({"bolood-fist","fist"}) );
        set("long","相傳這是一隻由阿修羅地獄來的血掌，遍身都透射著血紅色的光澤。\n");
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
                    set("material", "skin");
      set("value",1900);
        }
          init_fist(9);
        setup();
}
