#include <weapon.h>
inherit SWORD;
void create()
{
   set_name("明動劍",({"ming-dung long sword","sword"}));
   set("long","這是一把神武教護法八神將使用的武器。\n");
   set_weight(9000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("limit_str",10);
          set("value",1750);
		set("volume",2);
                set("material","iron");
        }
init_sword(28);
        setup();
}
