
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name("斷骨鐵棒",({"bone hammer","hammer"}) );
  set("long","一枝巨大的鐵棒，膂力稍弱者，根本連提都提不起來。\n");
  set_weight(30000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","枝");
    set("volume", 4);
    set("value", 3000);
  }
  init_hammer(50);
  set("material","iron");
  set("weapon_prop/con", 1);
  set("weapon_prop/str", 1);
  setup();        
}
