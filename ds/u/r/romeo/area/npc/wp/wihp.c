#include <weapon.h>

inherit WIHP;

void create()
{
        set_name("月牙鞭",({"moon-wihp","wihp"}) );
        set("long","相轉由九天之石造成的長鞭，因手柄成新月之形而得名。\n");
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
                    set("material", "rock");
      set("value",900);
        }
          init_wihp(8);
        setup();
}

