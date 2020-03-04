#include <weapon.h>
inherit STAFF;

void create()
{
  set_name("倒刺木棒",({"thorn stick","stick"}) );
  set("long","一把巨大的木棒，由堅硬的樹幹製成，上面滿佈倒刺，增加不少殺傷力。\n");
  set_weight(30000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","枝");
    set("volume", 3);
    set("value", 1200);
  }
  init_staff(45, TWO_HANDED);
  set("material","wood");
  set("weapon_prop/dex",-1);
  set("weapon_prop/str",1);
  setup();        
}
