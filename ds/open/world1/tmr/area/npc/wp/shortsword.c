#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("短劍",({"short sword","sword"}) );
          set("long","一把粗糙的短劍，通常被拿來貼身保護用的。\n");
          set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
		set("volume",2);
      set("value",600);
        }
              set("wield_msg","$N拿起了裝備$n充當武器。\n");
          init_sword(6);
        set("material","iron");
        setup();        
}
