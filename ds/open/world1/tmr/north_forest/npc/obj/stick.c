#include <weapon.h>
inherit STAFF;

void create()
{
  set_name("木棒",({"wood stick","stick"}) );
  set("long","一把巨大的木棒，由堅硬的樹幹製成。\n");
  set_weight(20000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","枝");
    set("volume", 2);
    set("value", 500);
  }
  init_staff(35, TWO_HANDED);
  set("material","wood");
  setup();        
}
