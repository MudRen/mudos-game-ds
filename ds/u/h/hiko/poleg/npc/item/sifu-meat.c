inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("虱目魚肉",({"sifu meat","meat"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一塊經過簡單處理的虱目魚肉。\n");
    set("unit", "塊");
    set("value",100);
    set("heal_ap",12);
    set("heal_hp",12);
    set("food_remaining",2);
  }
  setup();
  set("no_auc",1);
}





