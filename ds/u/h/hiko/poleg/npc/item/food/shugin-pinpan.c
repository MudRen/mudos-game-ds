#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIY"雙魚拼盤"NOR, ({ "shugin pinpan","pinpan" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一種由兩條不同魚肉作成的料理，做法精細，味道相當不錯。\n");
    set("unit","碗");
    set("value",2000);
    set("heal_hp",60);
    set("heal_ap",40);
    set("food_remaining",15);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}






