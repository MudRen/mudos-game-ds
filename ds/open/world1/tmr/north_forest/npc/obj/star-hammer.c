#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name(HIC"流星錘"NOR,({"star hammer","hammer"}) );
  set("long","一枝巨大的流星錘，由生鐵打造而成，上面佈滿尖銳的鐵刺，沾著不少血跡跟碎肉。\n");
  set_weight(30000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","枝");
    set("volume", 3);
    set("value", 2400);
  }
  init_hammer(55);
  set("material","iron");
  set("weapon_prop/con", 1);
  set("weapon_prop/str", 2);
  setup();        
}
