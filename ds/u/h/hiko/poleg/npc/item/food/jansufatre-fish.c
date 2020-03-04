#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIG"珍珠翡翠魚"NOR, ({ "jansu-fatre fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一種要用高超技藝的料理，而且配上圓滾滾的粉白色珍珠\n"
                "以及翠綠色白菜作襯，光是菜色便令人食指大動，是給有\n"
                "一定財力的人享用的名菜。\n");
    set("unit","碟");
    set("value",2000);
    set("heal_hp",75);
    set("heal_ap",75);
    set("heal_mp",30);
    set("food_remaining",16);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}








