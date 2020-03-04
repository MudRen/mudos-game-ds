#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
  set_name(HIB"水手彎刀"NOR, ({ "sailorman blade","blade" }) );
  set_weight(2300);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "一把有弧度短刀，一般都水手所使用。\n");
    set("material", "steel");
    set("value",1400);
    set("limit_str",10);
  }
  init_blade(15+random(4));
  setup();
}
