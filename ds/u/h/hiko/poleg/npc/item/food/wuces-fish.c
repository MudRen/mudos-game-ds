#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIY"五"HIW"色"HIY"香"HIR"魚"NOR, ({ "wuces fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一道擺\飾十分華美的料理，用了十分眾多的材料製作而成\n"
                "主菜是用各色魚種來調配，菜色很多樣化，感覺起來就是\n"
                "色彩十分艷麗，味道亦是絕佳。\n");
    set("unit","碟");
    set("value",3000);
    set("heal_hp",55);
    set("heal_ap",40);
    set("heal_mp",90);
    set("eat_msg","$N吃下$n。");
    set("eff_msg",HIG "你感到身上傷口復原了，全身舒暢。" NOR );
    set("food_remaining",20);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
 set("cure",([
         "head" : 5,
         "body" : 5,
         "right_arm" : 5,
         "left_arm" : 5,
            ]));
}












