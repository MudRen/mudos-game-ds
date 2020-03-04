#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(MAG"野葡萄"NOR, ({ "agrestal grape","grape" }));
  set("long",
      "長得小小的葡萄，酸酸澀澀的，吃起來味道還可以。\n"
     );
  set_weight(400);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
  }
  set("value", 100);
  set("food_remaining",1);
  set("heal_hp",50);  
  set("heal_ap",20);  
  setup();
}
