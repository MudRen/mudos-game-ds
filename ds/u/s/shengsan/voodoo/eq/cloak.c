
#include <armor.h>

inherit CLOAK;

void create()
{
  set_name("赤血披風",({"cloak"}));
  set("long","這是一件鮮紅色的披風\n");
	set_weight(3500);
  if( clonep() )
      set_default_object(__FILE__);
  else {
      set("material","hands");
      set("unit","件");
set("value",3800);
      set("armor_prop/armor",70);
      set("limit_lv",70);
  }

  setup();

}
