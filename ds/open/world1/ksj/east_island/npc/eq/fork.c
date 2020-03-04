#include <weapon.h>
inherit FORK;

void create()
{
  set_name("刺叉", ({"fork" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "前端分成兩枝的鐵叉，是一般盜匪常用的武器。\n");
    set("value",800);
    set("volume",4);
    set("material","steel");
  }
  init_fork(20,TWO_HANDED);
  setup();
}
