#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("鋼劍",({"short sword","sword"}) );
          set("long","一把用劣等鋼打造的長劍, 勉強可以用啦....\n");
          set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
                set("volume",2);
      set("value",1200);
        }
              set("wield_msg","$N拿起$n揮舞了兩下。\n");
          init_sword(16);
        set("material","steel");
        setup();        
}
