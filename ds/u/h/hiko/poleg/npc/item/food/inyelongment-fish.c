#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIG"魚"HIW"越"HIC"龍"HIW"門"NOR, ({ "inyelong-ment fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一道擺\飾十分華美的料理，旁邊配上雕刻精美的龍形飾菜\n"
                "以及有著很多的魚作主菜，菜色很多樣化，感覺起來就是\n"
                "非常賞心悅目，味道亦是一絕。\n");
    set("unit","碟");
    set("value",3000);
    set("heal_hp",55);
    set("heal_ap",90);
    set("heal_mp",40);
    set("eat_msg","$N吃了一口$n。");
    set("eff_msg",HIG "你感到身上的傷口慢慢復原了，全身舒暢。" NOR );
    set("food_remaining",20);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
   set("cure",([
         "head" : 5,
         "body" : 5,
        ]));
}










