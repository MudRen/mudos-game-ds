#include <weapon.h>
#include <ansi.h>

inherit FIST;

void create()
{
  set_name("爪",({"Claw", "claw" }) );
  set("long","
一把武術家用的爪。
\n");
      set_weight(0);
  if (clonep() )
             set_default_object(__FILE__);
    else {
      set("unit","把");
      set("value",0);
      set("material","iron");
      init_fist(99);
   }
setup();
}
