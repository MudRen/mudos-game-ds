#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIR"紅燒糖醋魚"NOR, ({ "hungsa tantsu","tantsu" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一種不易作出的料理，吃起來帶些微甜味，卻又有些鹹鹹的\n"
                "滋味非常特殊，是老饕的愛食，且也算是天下美食之一。\n");
    set("unit","碟");
    set("value",2000);
    set("heal_hp",30);
    set("heal_mp",80);
    set("food_remaining",15);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}







