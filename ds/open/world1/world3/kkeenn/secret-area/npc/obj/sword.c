#include <weapon.h>
inherit SWORD;
void create()
{
  set_name("弱光子劍",({"light sword","sword"}) );
  set("long","一把普通的弱光子劍，用來防身倒也足夠。\n");
      set_weight(3000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","把");
        set("value",800);
        set("volume",2);
        set("material","iron");

   }
        init_sword(12);
        setup();
}

