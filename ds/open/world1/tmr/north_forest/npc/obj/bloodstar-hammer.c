#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name(HIR"血流星錘"NOR,({"blood-star hammer","hammer"}) );
  set("long","一枝巨大的血流星錘，由生紅鐵打造而成，上面佈滿尖銳的鐵刺，沾著不少血跡跟碎肉。\n");
  set_weight(35000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","枝");
    set("volume", 4);
    set("value", 8000);
  }
  init_hammer(60);
  set("material","iron");
  set("weapon_prop/con", 1);
  set("weapon_prop/str", 3);
  setup();        
}
