#include <weapon.h>

inherit FIST;

void create()
{
    set_name("拳擊手套",({"boxing fist","boxing","fist"}) );
   set("long","常見拳擊的手套。\n");
        set_weight(2000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","個");
         set("value",1000);
        set("material","iron");
      init_fist(10);
   }
setup();
}


