#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
  set_name("《軍用》利劍",({"jun sword","sword"}) );
  set("long","一把很利的利劍，是軍人長用的武器。\n");
      set_weight(4500);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","把");
      set("value",1800);
        set("material","iron");
      init_sword(14);

   }
setup();
}

