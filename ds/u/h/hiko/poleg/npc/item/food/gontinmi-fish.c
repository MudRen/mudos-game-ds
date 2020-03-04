#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIR"宮"HIR"廷"HIY"秘"HIY"魚"NOR, ({ "gontinmi fish","fish" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "這是傳說由宮廷御廚流出的處方而成，所用材料價格不菲\n"
                "而其所用的調味方式亦是獨家，所以極難製作成功\，因此\n"
                "若要吃到這料理，也必須有極好的手藝。\n");
    set("unit","碟");
    set("value",3000);
    set("heal_hp",60);
    set("heal_ap",85);
    set("heal_mp",85);
    set("eat_msg","$N吃了一口$n。");
    set("eff_msg",HIG "你感到身上傷口復原了，全身舒暢。" NOR );
    set("food_remaining",24);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
 set("cure",([
         "head" : 7,
         "body" : 7,
         "right_arm" : 7,
         "left_leg" : 7,
            ]));
}













