inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("海米",({"sea rice","rice"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一包已經處理好的海米十分方便。\n");
    set("unit", "包");
    set("value",370);
    set("heal_ap",30);
    set("heal_hp",30);
    set("food_remaining",4);
  }
  setup();
  set("no_auc",1);
}



