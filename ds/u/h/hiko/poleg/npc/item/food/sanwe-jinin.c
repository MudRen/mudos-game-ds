#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIY"三味蒸魚"NOR, ({ "sanwe jinin","jinin" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "用三種不同魚去調配的料理，風味絕佳，吃起來十分鮮美。\n");
    set("unit","碟");
    set("value",2000);
    set("heal_hp",50);
    set("heal_ap",80);
    set("food_remaining",15);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}





