#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(HIW"石露冰晶"NOR, ({ "ice crystal","crystal" }));
  set("long",
      "岩層富含豐富礦物質的水凝結而成，要形成如這顆指頭大小的冰晶，\n"
     +"需要１０年之久，有的人視它為一種稀有的藥材。\n"
     );
  set_weight(100);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "塊");
  }
  set("value", 1500);
  set("food_remaining",1);
  set("heal_hp",300);  
  set("heal_ap",200);  
  setup();
}
