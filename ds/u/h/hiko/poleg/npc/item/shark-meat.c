inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("鯊魚肉",({"shark meat","meat"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一塊經過簡單處理的鯊魚肉，營養略高。\n");
    set("unit", "塊");
    set("value",160);
    set("heal_ap",4);
    set("heal_hp",24);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}






