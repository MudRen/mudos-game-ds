#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(YEL"肉芝"NOR, ({ "carrion fungus","fungus" }));
  set("long",
      "生長於腐肉上的蕈類，一般難得見到，其藥效相當好，是五芝之一，\n"
     +"媲美石芝、木芝、草芝、菌芝。\n"
     );
  set_weight(700);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "株");
  }
  set("value", 3000);
  set("food_remaining",2);
  set("heal_hp",300);  
  set("heal_ap",300);
  set("heal_mp",300);    
  setup();
}
