#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(RED"野果"NOR, ({ "wild fruit","fruit" }));
  set("long",
      "野生的果實，稍微沾有塵土，吃起來帶點苦澀。\n"
     );
  set_weight(400);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "粒");
  }
  set("value", 10);
  set("food_remaining",2);
  set("heal_mp",15);  
  setup();
}
