#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
  set_name("菊池槍", ({ "kikuchi pike","pike" }) );
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_str",20);
    set("limit_skill",15);
    set("limit_lv",10);
    set("unit", "把");
    set("long", "素長槍的一種，刀尖設計為單面有刃。\n");
    set("value",1500);
    set("volume",5);
    set("material","steel");
  }
  init_fork(30,TWO_HANDED);
  setup();
}
