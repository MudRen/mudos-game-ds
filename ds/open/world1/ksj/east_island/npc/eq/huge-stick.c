#include <weapon.h>
inherit STAFF;

void create()
{
  set_name("大木棒",({"huge stick","stick"}) );
  set("long","一把巨大的木棒，由整枝樹幹製成！\n");
  set_weight(50000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","枝");
    set("volume",5);
    set("value",0);
    set("limit_str",105);
  }
  init_staff(50,TWO_HANDED);
  set("weapon_prop/hit",15);
  set("material","wood");
  setup();        
}
