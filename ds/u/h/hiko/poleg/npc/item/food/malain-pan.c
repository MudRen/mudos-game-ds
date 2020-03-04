#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIR"麻辣魚片"NOR, ({ "mala-in pan","pan" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一道精心料理的魚片，吃起來著濃厚辣味，卻又口感十足\n"
                "滋味非凡，是性嗜辣食的人的最愛，是一種奇特的料理。\n");
    set("unit","碟");
    set("value",2000);
    set("heal_hp",40);
    set("heal_ap",70);
    set("heal_mp",70);
    set("food_remaining",16);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}







